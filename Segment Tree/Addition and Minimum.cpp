#include<bits/stdc++.h>
using namespace std;
#define int long long int

struct segment{
    int sz{};
    vector<int> operation, lazy;
    void init(int n){
        sz = 1;
        while (sz < n) sz *= 2;
        operation.assign(2 * sz, 0);
        lazy.assign(2 * sz, 0);
    }
    void add(int l, int r, int v, int x, int lx, int rx){
        if(lx >= r or l >= rx)return;
        if(lx >= l and rx <= r){
            operation[x] += v;
            lazy[x] += v;
            return;
        }
        int m = (lx + rx) / 2;
        add(l, r, v, 2 * x + 1, lx, m);
        add(l, r, v, 2 * x + 2, m, rx);
        lazy[x] = min(lazy[2 * x + 1], lazy[2 * x + 2]) + operation[x];
    }
    void add(int l, int r, int v){
        add(l, r, v, 0, 0, sz);
    }
    int get(int l, int r, int x, int lx, int rx){
        if(lx >= r or l >= rx)return INT_MAX;
        if(lx >= l and rx <= r){
            return lazy[x];
        }
        int m = (lx + rx) / 2;
        int m1 = get(l, r, 2 * x + 1, lx, m);
        int m2 = get(l, r, 2 * x + 2, m, rx);
        return min(m1, m2) + operation[x];
    }
    int get(int l, int r){
        return get(l, r, 0, 0, sz);
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    segment st;
    int n, m;
    cin >> n >> m;
    st.init(n);
    while (m--){
        int type;
        cin >> type;
        if(type == 1){
            int l, r, v;
            cin >> l >> r >> v;
            st.add(l, r, v);
        }else{
            int l, r;
            cin >> l >> r;
            cout << st.get(l, r) << '\n';
        }
    }
    return 0;
}
