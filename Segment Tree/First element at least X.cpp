#include<bits/stdc++.h>
using namespace std;

struct segment{
    int sz;
    vector<int> a;
    void init(int n){
        sz = 1;
        while (sz < n)sz *= 2;
        a.assign(2 * sz, 0);
    }
    int NEUTRAL = INT_MIN;
    int merge(int x, int y){
        return max(x, y);
    }
    int single(int v){
        return v;
    }
    void build(vector<int> &aa, int x, int lx, int rx){
        if(rx - lx == 1){
            if(lx < (int) aa.size()){
                a[x] = single(aa[lx]);
            }
            return;
        }
        int m = (lx + rx) / 2;
        build(aa, 2 * x + 1, lx, m);
        build(aa, 2 * x + 2, m, rx);
        a[x] = merge(a[2 * x + 1] , a[2 * x + 2]);
    }
    void build(vector<int> &aa){
        build(aa, 0, 0, sz);
    }
    void set(int i, int v, int x, int lx, int rx){
        if(rx - lx == 1){
            a[x] = single(v);
            return;
        }
        int m = (lx + rx) / 2;
        if(i < m){
            set(i, v, 2 * x + 1, lx, m);
        }else{
            set(i, v, 2 * x + 2, m, rx);
        }
        a[x] = merge(a[2 * x + 1] , a[2 * x + 2]);
    }
    void set(int i, int v){
        set(i, v, 0, 0, sz);
    }
    int query(int val, int x, int lx, int rx){
        if(a[x] < val)return -1;
        if(rx - lx == 1){
            return lx;
        }
        int m = (lx + rx) / 2;
        int res = query(val, 2 * x + 1, lx, m);
        if(res == -1){
            res = query(val, 2 * x + 2, m, rx);
        }
        return res;
    }
    int query(int x){
        return query(x, 0, 0, sz);
    }
};

int main(){
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
           int x;
           cin >> x;
           int ans = st.query(x);
           if(ans != INT_MAX)cout << ans << '\n';
           else cout << "-1" << '\n';
       }
    }
    return 0;
}
