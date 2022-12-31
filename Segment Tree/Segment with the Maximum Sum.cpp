#include<bits/stdc++.h>
using namespace std;
#define int long long int

struct item{
    int seg, pref, suf, sum;
};

struct segment{
    int sz;
    vector<item> a;
    void init(int n){
        sz = 1;
        while (sz < n)sz *= 2;
        a.assign(2 * sz, {0, 0, 0, 0});
    }
    item NEUTRAL = {0, 0, 0, 0};
    item merge(item x, item y){
        return {
           max({x.seg, y.seg, x.suf + y.pref}),
           max(x.pref, x.sum + y.pref),
           max(y.suf, y.sum + x.suf),
            x.sum + y.sum
        };
    }
    item single(int v){
        if(v > 0){
            return {v, v, v, v};
        }else{
            return {0, 0, 0, v};
        }
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
    item query(int l, int r, int x, int lx, int rx){
        if(lx >= r or l >= rx)return NEUTRAL;
        if(lx >= l and rx <= r)return a[x];
        int m = (lx + rx) / 2;
        return merge(query(l, r, 2 * x + 1, lx, m) , query(l, r, 2 * x + 2, m, rx));
    }
    item query(int l, int r){
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
    cout << st.query(0, n).seg << '\n';
    while (m--){
       int i, v;
       cin >> i >> v;
       st.set(i, v);
       cout << st.query(0, n).seg << '\n';
    }
    return 0;
}
