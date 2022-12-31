#include<bits/stdc++.h>
using namespace std;
#define int long long int

struct segment{
    int sz;
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
        a[x] = min(a[2 * x + 1] , a[2 * x + 2]);
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
        a[x] = min(a[2 * x + 1] , a[2 * x + 2]);
    }
    void set(int i, int v){
        set(i, v, 0, 0, sz);
    }
    int query(int l, int r, int x, int lx, int rx){
        if(lx >= r or l >= rx)return INT_MAX;
        if(lx >= l and rx <= r)return a[x];
        int m = (lx + rx) / 2;
        return min(query(l, r, 2 * x + 1, lx, m) , query(l, r, 2 * x + 2, m, rx));
    }
    int query(int l, int r){
        return query(l, r, 0, 0, sz);
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    segment st;
    st.init(n);
    vector<int> a(n);
    for(int i = 0; i < n; i++){
      cin >> a[i];
    }
    st.build(a);
    while (m--){
        int type;
        cin >> type;
        if(type == 1){
            int i, v;
            cin >> i >> v;
            st.set(i, v);
        }else{
            int l, r;
            cin >> l >> r;
            cout << st.query(l, r) << '\n';
        }
    }
    return 0;
}
