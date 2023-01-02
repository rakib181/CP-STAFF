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
            if(lx < (int) v.size()) a[x] += v[lx];
            return;
        }
        int m = (lx + rx) / 2;
        build(v, 2 * x + 1, lx, m);
        build(v, 2 * x + 2, m, rx);
    }
    void build(vector<int> &v){
        build(v, 0, 0, sz);
    }
    void add(int l, int r, int v, int x, int lx, int rx){
        if(lx >= r or l >= rx)return;
        if(lx >= l and rx <= r){
            a[x] += v;
            return;
        }
        int m = (lx + rx) / 2;
        add(l, r, v, 2 * x + 1, lx, m);
        add(l, r, v, 2 * x + 2, m, rx);
    }
    void add(int l, int r, int v){
        add(l, r, v, 0, 0, sz);
    }
    int get(int i, int x, int lx, int rx){
        if(rx - lx == 1){
            return a[x];
        }
        int m = (lx + rx) / 2, res;
        if(i < m){
            res = get(i, 2 * x + 1, lx, m);
        }else{
            res = get(i, 2 * x + 2, m, rx);
        }
        return a[x] + res;
    }
    int get(int i){
        return get(i, 0, 0, sz);
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
           int i;
           cin >> i;
           cout << st.get(i) << '\n';
       }
    }
    return 0;
}
