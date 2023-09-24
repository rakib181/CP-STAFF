#include<bits/stdc++.h>
using namespace  std;
using ll = long long;

const int N = 2e5 + 9, p1 = 137, p2 = 277, mod1 = 1e9 + 7, mod2 = 1e9 + 9;
pair<int, int> pw[N], ipw[N];

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

struct HASH {
    pair<int, int> prefix[N];
    void build(string &s) {
        for (int i = 0; i < (int) s.size(); i++) {
            prefix[i].first = 1LL * s[i] * pw[i].first % mod1;
            if (i)prefix[i].first = 1LL * (1LL * prefix[i].first + prefix[i - 1].first) % mod1;
            prefix[i].second = 1LL * s[i] * pw[i].second % mod2;
            if (i)prefix[i].second = 1LL * (1LL * prefix[i].second + prefix[i - 1].second) % mod2;
        }
    }

    pair<int, int> get_hash(int i, int j) {
        assert(i <= j);
        pair<int, int> ans = {0, 0};
        ans.first = prefix[j].first;
        if (i) ans.first = 1LL * (1LL * (1LL * ans.first - prefix[i - 1].first) + mod1) % mod1;
        ans.first = 1LL * ans.first * ipw[i].first % mod1;
        ans.second = prefix[j].second;
        if (i) ans.second = 1LL * (1LL * (1LL * ans.second - prefix[i - 1].second) + mod2) % mod2;
        ans.second = 1LL * ans.second * ipw[i].second % mod2;
        return ans;
    }
}S, T;


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cal();
    string a, b;
    cin >> a >> b;
    S.build(a);
    T.build(b);
    int n = (int) a.size();
    int m = (int) b.size();
    map<pair<int, int>, int> cnt;
    for(int len = 1; len <= n; len++){
        if(n % len == 0){
            bool f = true;
            auto main = S.get_hash(0, len - 1);
            for(int i = 0; i + len - 1 < n; i += len){
                int l = i, r = i + len - 1;
                auto p = S.get_hash(l, r);
                f &= (p == main);
            }
            if(f){
                cnt[main] += 1;
            }
        }
    }
    for(int len = 1; len <= m; len++){
        if(m % len == 0){
            bool f = true;
            auto main = T.get_hash(0, len - 1);
            for(int i = 0; i + len - 1 < m; i += len){
                int l = i, r = i + len - 1;
                auto p = T.get_hash(l, r);
                f &= (p == main);
            }
            if(f){
                cnt[main] += 1;
            }
        }
    }
    int ans = 0;
    for(auto [x, y]: cnt){
        ans += (y == 2);
    }
    cout << ans << '\n';
    return 0;
}
