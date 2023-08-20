#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 3005, p1 = 131, p2 = 137, mod1 = 1e9 + 7, mod2 = 1e9 + 9;
pair<int, int> pw[N], ipw[N];

int bin(int x, int y, int mod){
    int ans = 1;
    while(y){
        if(y & 1)ans = 1LL * ans * x % mod;
        x = 1LL * x * x % mod;
        y >>= 1;
    }
    return ans;
}

void cal(){
    pw[0] = {1, 1};
    ipw[0] = {1, 1};
    for(int i = 1; i < N; i++){
        pw[i].first = 1LL * pw[i - 1].first * p1 % mod1;
        pw[i].second = 1LL * pw[i - 1].second * p2 % mod2;
    }
    int ip1 = bin(p1, mod1 - 2, mod1);
    int ip2 = bin(p2, mod2 - 2, mod2);
    for(int i = 1; i < N; i++){
        ipw[i].first = 1LL * ipw[i - 1].first * ip1 % mod1;
        ipw[i].second = 1LL * ipw[i - 1].second * ip2 % mod2;
    }
}

struct Hashing{
    string s;
    int n;
    vector<pair<int, int>> hs;
    explicit Hashing(string &s){
        this -> n = (int) s.size();
        this -> s = s;
        hs.emplace_back(0, 0);
        for(int i = 0; i < n; i++){
            pair<int, int> p;
            p.first = 1LL * (1LL * hs[i].first + 1LL * pw[i].first * s[i] % mod1) % mod1;
            p.second = 1LL * (1LL * hs[i].second + 1LL * pw[i].second * s[i] % mod2) % mod2;
            hs.emplace_back(p);
        }
    }
    pair<int, int> get_hash(int l, int r){
        pair<int, int> ans;
        ans.first = 1LL * (1LL * hs[r].first - hs[l - 1].first + mod1) * 1LL * ipw[l - 1].first % mod1;
        ans.second = 1LL * (1LL * hs[r].second - hs[l - 1].second + mod2) * 1LL * ipw[l - 1].second % mod2;
        return ans;
    }
};

pair<int, int> hashing(string &a){
    pair<int, int> ans = {0, 0};
    for(int i = 0; i < (int) a.size(); i++){
          ans.first = 1LL * (1LL * ans.first + 1LL * pw[i].first * a[i] % mod1) % mod1;
          ans.second = 1LL * (1LL * ans.second + 1LL * pw[i].second * a[i] % mod2) % mod2;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cal();
    string k;
    for(int i = 0; i < 26; i++){
        k += char(i + 'a');
    }
    string s;
    for(int i = 0; i < 85; i++){
        s += k;
    }
    Hashing hash(s);
    int t;
    cin >> t;
    while(t--){
        string p;
        cin >> p;
        pair<int, int> pat = hashing(p);
        int n = (int) s.size(), m = (int) p.size();
        bool f = false;
        for(int i = 1; i + m - 1 <= n; i++){
            f |= (hash.get_hash(i, i + m - 1) == pat);
        }
        f ? cout << "YES\n" : cout << "NO\n";
    }
    return 0;
}
