#include<bits/stdc++.h>
using namespace std;
#define int long long int

struct segment{
    int sz{}, NO_OPERATION = LONG_LONG_MAX;
    vector<int> a;
    void init(int n){
        sz = 1;
        while (sz < n) sz *= 2;
        a.assign(2 * sz, 0);
    }
    int operation(int a, int b) const{
        if(b == NO_OPERATION)return a;
        return b;
    }
    void apply_operation(int &a, int b) const{
        a = operation(a, b);
    }

    void propagate(int x, int lx, int rx){
        if(rx - lx == 1)return;
        apply_operation(a[2 * x + 1], a[x]);
        apply_operation(a[2 * x + 2], a[x]);
        a[x] = NO_OPERATION;
    }
    void add(int l, int r, int v, int x, int lx, int rx){
        propagate(x, lx, rx);
        if(lx >= r or l >= rx)return;
        if(lx >= l and rx <= r){
            apply_operation(a[x], v);
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
        return operation(res, a[x]);
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
