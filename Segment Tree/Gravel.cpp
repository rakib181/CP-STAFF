#include<bits/stdc++.h>
using namespace std;
#define int long long int

struct segment{
    int sz{};
    vector<int> seg, operation;
    void init(int n, int c){
        sz = 1;
        while (sz < n) sz *= 2;
        seg.assign(2 * sz, c);
        operation.assign(2 * sz, 0);
    }
    void propagate(int x, int lx, int rx){
        seg[x] += operation[x];
        if(rx - lx != 1){
            operation[2 * x + 1] += operation[x];
            operation[2 * x + 2] += operation[x];
        }
        operation[x] = 0;
    }
    void add(int l, int r, int v, int x, int lx, int rx){
        propagate(x, lx, rx);
        if(lx >= r or l >= rx)return;
        if(lx >= l and rx <= r){
            operation[x] += v;
            propagate(x, lx, rx);
            return;
        }
        int m = (lx + rx) / 2;
        add(l, r, v, 2 * x + 1, lx, m);
        add(l, r, v, 2 * x + 2, m, rx);
        seg[x] = seg[2 * x + 1] + seg[2 * x + 2];
    }
    void add(int l, int r, int v){
        add(l, r, v, 0, 0, sz);
    }
    int query(int i, int x, int lx, int rx){
        propagate(x, lx, rx);
        if(rx - lx == 1){
            return seg[x];
        }
        int m = (lx + rx) / 2;
        if(i < m){
            return query(i, 2 * x + 1, lx, m);
        }else{
            return query(i, 2 * x + 2, m, rx);
        }
    }
    int query(int i){
        return query(i, 0, 0, sz);
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    segment st;
    int n, q, c;
    cin >> n >> q >> c;
    st.init(n, c);
    while (q--){
        char type;
        cin >> type;
        if(type == 'S'){
            int l, r, v;
            cin >> l >> r >> v;
            l--;
            st.add(l, r, v);
        }else{
            int i;
            cin >> i;
            i--;
            cout << st.query(i) << '\n';
        }
    }
    return 0;
}
