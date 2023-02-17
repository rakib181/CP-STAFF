#include<bits/stdc++.h>
using namespace std;
#define int long long int

struct segment{
    int sz{};
    vector<int> a;
    void init(int n){
        sz = 1;
        while (sz < n) sz *= 2;
        a.assign(2 * sz, 0);
    }
    void build(vector<int> &v, int x, int lx, int rx){
        if(rx - lx == 1){
            if(lx < (int) v.size())a[x] = v[lx];
            return;
        }
        int m = (lx + rx) / 2;
        build(v, 2 * x + 1, lx, m);
        build(v, 2 * x + 2, m, rx);
        a[x] = a[2 * x + 1] + a[2 * x + 2];
    }
    void build(vector<int> &v){
        build(v, 0, 0, sz);
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

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--){
        segment st;
        int n, q;
        cin >> n >> q;
        st.init(n);
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            a[i] = (x & 1);
        }
        st.build(a);
        while (q--){
            int l, r;
            cin >> l >> r;
            l--, r--;
            int odd = st.query(l, r + 1);
            int even = (r - l + 1) - odd;
            cout << ((odd * (odd - 1) * (odd - 2)) / 6) + (odd * ((even * (even - 1)) / 2)) << ' ';
        }
        cout << '\n';
    }
    return 0;
}
