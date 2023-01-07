#include<bits/stdc++.h>
using namespace std;
#define int long long int

struct segment{
    int sz{};
    vector<int> a;
    void init(int n){
        sz = 1;
        while (sz < n) sz *= 2;
        a.assign(2 * sz, INT_MAX);
    }
    void set(int i, int val, int x, int lx, int rx){
        if(rx - lx == 1){
            a[x] = val;
            return;
        }
        int m = (lx + rx) / 2;
        if(i < m){
            set(i, val, 2 * x + 1, lx, m);
        }else{
            set(i, val, 2 * x + 2, m, rx);
        }
        a[x] = min(a[2 * x + 1] , a[2 * x + 2]);
    }
    void set(int i, int val){
        set(i, val, 0, 0, sz);
    }
    int query(int l, int r, int p, int x, int lx, int rx){
        if(lx >= r or l >= rx)return 0;
        if(rx - lx == 1){
            if(a[x] <= p){
                set(lx, INT_MAX);
                return 1;
            }
            return 0;
        }
        int m = (lx + rx) / 2;
        if(a[x] <= p){
            int s1 = 0, s2 = 0;
            if(a[2 * x + 1] <= p) s1 = query(l, r, p, 2 * x + 1, lx, m);
            if(a[2 * x + 2] <= p) s2 = query(l, r, p, 2 * x + 2, m, rx);
            return s1 + s2;
        }
       return 0;
    }
    int query(int l, int r, int p){
        return query(l, r, p,0, 0, sz);
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    segment st;
    int n, q;
    cin >> n >> q;
    st.init(n);
    while (q--){
        int type;
        cin >> type;
        if(type == 1){
            int i, v;
            cin >> i >> v;
            st.set(i, v);
        }else{
            int l, r, p;
            cin >> l >> r >> p;
            cout << st.query(l, r, p) << '\n';
        }
    }
    return 0;
}
