#include<bits/stdc++.h>
using namespace std;
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
        if(i > j)return {0, 0};
        pair<int, int> ans = {0, 0};
        ans.first = prefix[j].first;
        if (i) ans.first = 1LL * (1LL * (1LL * ans.first - prefix[i - 1].first) + mod1) % mod1;
        ans.first = 1LL * ans.first * ipw[i].first % mod1;
        ans.second = prefix[j].second;
        if (i) ans.second = 1LL * (1LL * (1LL * ans.second - prefix[i - 1].second) + mod2) % mod2;
        ans.second = 1LL * ans.second * ipw[i].second % mod2;
        return ans;
    }
}S;

pair<int, int> string_hash(string &s){
    pair<int, int> ans = {0, 0};
    int n = (int) s.size();
    for(int i = 0; i < n; i++){
        ans.first = 1LL * (1LL * ans.first +  1LL * s[i] * pw[i].first % mod1) % mod1;
        ans.second = 1LL * (1LL * ans.second + 1LL * s[i] * pw[i].second % mod2) % mod2;
    }
    return ans;
}

pair<int, int> Merge(int pos, pair<int, int> l, pair<int, int> r, string str){
        pair<int, int> mid = string_hash(str);
        mid.first = 1LL * mid.first * pw[pos].first % mod1;
        mid.second = 1LL * mid.second * pw[pos].second % mod2;
        r.first = 1LL * r.first * pw[pos + 3].first % mod1;
        r.second = 1LL * r.second * pw[pos + 3].second % mod2;
        pair<int, int> ans = l;
        ans.first = 1LL * (1LL * ans.first + mid.first + r.first) % mod1;
        ans.second = 1LL * (1LL * ans.second + mid.second + r.second) % mod2;
        return ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cal();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        S.build(s);
        set<pair<int, int>> se;
        for(int i = 0; i + 2 < n; i++){
            string str;
            str += s[i + 1];
            str += s[i + 2];
            str += s[i];
            pair<int, int> l = S.get_hash(0, i - 1);
            pair<int, int> r = S.get_hash(i + 3, n - 1);
            pair<int, int> ans = Merge(i, l, r, str);
            se.insert(ans);
        }
        cout << (int) se.size() << '\n';
    }
    return 0;
}
