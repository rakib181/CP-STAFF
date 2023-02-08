#include<bits/stdc++.h>
using namespace std;
#define int long long int

struct segment{
    int sz{};
    vector<int> a;
    void init(int n){
        sz = 1;
        while (sz < n)sz *= 2;
        a.assign(2 * sz, 0);
    }
    void build(vector<int> &aa, int x, int lx, int rx){
        if(rx - lx == 1){
            if(lx < (int) aa.size()){
                a[x] = aa[lx];
            }
            return;
        }
        int m = (lx + rx) / 2;
        build(aa, 2 * x + 1, lx, m);
        build(aa, 2 * x + 2, m, rx);
        a[x] = a[2 * x + 1] + a[2 * x + 2];
    }
    void build(vector<int> &aa){
        build(aa, 0, 0, sz);
    }
    void set(int i, int v, int x, int lx, int rx){
        if(rx - lx == 1){
            a[x] = v;
            return;
        }
        int m = (lx + rx) / 2;
        if(i < m){
            set(i, v, 2 * x + 1, lx, m);
        }else{
            set(i, v, 2 * x + 2, m, rx);
        }
        a[x] = a[2 * x + 1] + a[2 * x + 2];
    }
    void set(int i, int v){
        set(i, v, 0, 0, sz);
    }
    int query(int l, int r, int x, int lx, int rx){
        if(lx >= r or l >= rx)return 0;
        if(lx >= l and rx <= r)return a[x];
        int m = (lx + rx) / 2;
        return query(l, r, 2 * x + 1, lx, m) + query(l, r, 2 * x + 2, m, rx);
    }
    int query(int l, int r){
        return query(l, r, 0, 0, sz);
    }
};

int32_t main(){
    int tt, cs = 1;
    cin >> tt;
    while (tt--) {
        cout << "Case " << cs++ << ":" << '\n';
        int n, q;
        cin >> n >> q;
        segment st;
        st.init(n);
        vector<int> a(n), cal(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            cal[i] = (n - 1 - 2 * i) * a[i];
        }
        for (int i = 0; i < n; i++) {
            st.set(i, cal[i]);
        }
        while (q--) {
            int type;
            cin >> type;
            if (type) {
                cout << st.query(0, n) << '\n';
            } else {
                int i, v;
                cin >> i >> v;
                st.set(i, (n - 1 - 2 * i) * v);
            }
        }
    }
    return 0;
}
