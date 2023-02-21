#include<bits/stdc++.h>
using namespace std;
#define int long long int

struct segment{
    int sz{};
    vector<pair<int, int>> a;
    void init(int n){
        sz = 1;
        while (sz < n) sz *= 2;
        a.assign(2 * sz, {0, 0});
    }

    pair<int, int> pull(pair<int, int> &x, pair<int, int> &y){
        pair<int, int> t;
        t.first = __gcd(x.first, y.first);
        t.second = 0;
        if(y.first and x.first % y.first == 0){
            t.second += y.second;
        }
        if(x.first and y.first % x.first == 0){
            t.second += x.second;
        }
        return t;
    }

    void build(vector<int> &v, int x, int lx, int rx){
        if(rx - lx == 1){
            if(lx < (int) v.size())a[x] = {v[lx], 1};
            return;
        }
        int m = (lx + rx) / 2;
        build(v, 2 * x + 1, lx, m);
        build(v, 2 * x + 2, m, rx);
        a[x] = pull(a[2 * x + 1] , a[2 * x + 2]);
    }
    void build(vector<int> &v){
        build(v, 0, 0, sz);
    }

    pair<int, int> combine(pair<int, int> x, pair<int, int> y){
        pair<int, int> t;
        t.first = __gcd(x.first, y.first);
        t.second = 0;
        if(x.first == 0 and y.first == 0)return t;
        if(x.first == 0)return y;
        if(y.first == 0)return x;
        if(y.first and x.first % y.first == 0){
            t.second += y.second;
        }
        if(x.first and y.first % x.first == 0){
            t.second += x.second;
        }
        return t;
    }
    pair<int, int> query(int l, int r, int x, int lx, int rx){
        if(lx >= r or l >= rx)return make_pair(0, 0);
        if(lx >= l and rx <= r)return a[x];
        int m = (lx + rx) / 2;
        return combine(query(l, r, 2 * x + 1, lx, m), query(l, r, 2 * x + 2, m, rx));
    }
    pair<int, int> query(int l, int r){
        return query(l, r, 0, 0, sz);
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    segment st;
    int n;
    cin >> n;
    st.init(n);
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    st.build(a);
    int q;
    cin >> q;
    while (q--){
        int l, r;
        cin >> l >> r;
        l--;
        cout << (r - l) - st.query(l, r).second << '\n';
    }
    return 0;
}
