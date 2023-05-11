#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e6 + 9, p1 = 137, p2 = 277, mod1 = 1e9 + 7, mod2 = 1e9 + 9;
pair<int, int> pw[N], ipw[N], a[N];

int bin(int x, int y, int mod) {
    int ans = 1;
    while (y) {
        if (y & 1) ans = 1LL * ans * x % mod;
        x = 1LL * x * x % mod;
        y >>= 1;
    }
    return ans;
}


void cal() {
    pw[0] = {1, 1};
    for (int i = 1; i < N; i++) {
        pw[i].first = 1LL * pw[i - 1].first * p1 % mod1;
        pw[i].second = 1LL * pw[i - 1].second * p2 % mod2;
    }
    int ip1 = bin(p1, mod1 - 2, mod1);
    int ip2 = bin(p2, mod2 - 2, mod2);
    ipw[0] = {1, 1};
    for (int i = 1; i < N; i++) {
        ipw[i].first = 1LL * ipw[i - 1].first * ip1 % mod1;
        ipw[i].second = 1LL * ipw[i - 1].second * ip2 % mod2;
    }
}


struct ST{
    pair<int, int> t[4 * N];
    pair<int, int> pull(pair<int, int> x, pair<int, int> y){
        pair<int, int> ans;
        ans = {(x.first + y.first) % mod1, (x.second + y.second) % mod2};
        return ans;
    }

    pair<int, int> combine(pair<int, int> x, pair<int, int> y){
        pair<int, int> ans;
        ans = {(x.first + y.first) % mod1, (x.second + y.second) % mod2};
        return ans;
    }
    void build(int node, int b, int e){
        if(b == e){
            t[node] = a[b];
            return;
        }
        int m = (b + e) >> 1;
        build(2 * node, b, m);
        build(2 * node + 1, m + 1, e);
        t[node] = pull(t[2 * node], t[2 * node + 1]);
    }

    void upd(int node, int b, int e, int i, pair<int, int> v){
        if(b > i or e < i)return;
        if(b == e){
            t[node] = v;
            return;
        }
        int m = (b + e) >> 1;
        upd(2 * node, b, m, i, v);
        upd(2 * node + 1, m + 1, e, i, v);
        t[node] = pull(t[2 * node], t[2 * node + 1]);
    }

    pair<int, int> query(int node, int b, int e, int l, int r){
        if(b > r or e < l)return {0, 0};
        if(b >= l and e <= r){
            return t[node];
        }
        int m = (b + e) >> 1;
        return combine(query(2 * node, b, m, l, r), query(2 * node + 1, m + 1, e, l, r));
    }
}st1, st2;

pair<int, int> main_hs(pair<int, int> x, int i){
    pair<int, int> ans;
    ans = {1LL * x.first * ipw[i - 1].first % mod1, 1LL * x.second * ipw[i - 1].second % mod2};
    return ans;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cal();
    int n, q;
    cin >> n >> q;
    string s, rev;
    cin >> s;
    rev = s;
    reverse(rev.begin(), rev.end());
    for(int i = 0; i < n; i++){
        a[i + 1].first = 1LL * s[i] * pw[i].first % mod1;
        a[i + 1].second = 1LL * s[i] * pw[i].second % mod2;
    }
    st1.build(1, 1, n);
    for(int i = 0; i < n; i++){
        a[i + 1].first = 1LL * rev[i] * pw[i].first % mod1;
        a[i + 1].second = 1LL * rev[i] * pw[i].second % mod2;
    }
    st2.build(1, 1, n);
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
           int i; char c;
           cin >> i >> c;
           pair<int, int> val;
           val = {1LL * c * pw[i - 1].first % mod1, 1LL * c * pw[i - 1].second % mod2};
           st1.upd(1, 1, n, i, val);
           val = {1LL * c * pw[n - i].first % mod1, 1LL * c * pw[n - i].second % mod2};
           st2.upd(1, 1, n, n - i + 1, val);
        }else{
            int l, r;
            cin >> l >> r;
            auto h1 = st1.query(1, 1, n, l, r);
            auto h2 = st2.query(1, 1, n, n - r + 1, n - l + 1);
            if(main_hs(h1, l) == main_hs(h2, n - r + 1)){
                cout << "YES\n";
            }else cout << "NO\n";
        }
    }
    return 0;
}
