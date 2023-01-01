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
           if(lx < (int) v.size()) a[x] = v[lx];
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
        a[x] = a[2 * x + 1] + a[2 * x + 2];
    }
    void set(int i, int val){
        set(i, val, 0, 0, sz);
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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    segment st;
    int n;
    cin >> n;
    st.init(n);
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(i & 1) a[i] *= -1;
    }
    st.build(a);
    int q;
    cin >> q;
    while (q--){
        int type;
        cin >> type;
        if(type == 0){
            int i, j;
            cin >> i >> j;
            i--;
            if(i & 1) j *= -1;
            st.set(i, j);
        }else{
            int l, r;
            cin >> l >> r;
            l--;
            int ans = st.query(l, r);
            if(l & 1) ans *= -1;
            cout << ans << '\n';
        }
    }
    return 0;
}
