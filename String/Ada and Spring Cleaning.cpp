#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 9, p1 = 137, p2 = 277, mod1 = 1e9 + 7, mod2 = 1e9 + 9;
pair<int, int> pw[N], ipw[N], prefix[N];

int bin(int x, int y, int mod){
    int ans = 1;
    while(y){
        if(y & 1) ans = 1LL * ans * x % mod;
        x = 1LL * x * x % mod;
        y >>= 1;
    }
    return ans;
}
void cal(){
    pw[0] = {1, 1};
    for(int i = 1; i < N; i++){
        pw[i].first = 1LL * pw[i - 1].first * p1 % mod1;
        pw[i].second = 1LL * pw[i - 1].second * p2 % mod2;
    }
    int ip1 = bin(p1, mod1 - 2, mod1);
    int ip2 = bin(p2, mod2 - 2, mod2);
    ipw[0] = {1, 1};
    for(int i = 1; i < N; i++){
        ipw[i].first = 1LL * ipw[i - 1].first * ip1 % mod1;
        ipw[i].second = 1LL * ipw[i - 1].second * ip2 % mod2;
    }
}

void build(string &s){
    int n = (int) s.size();
    for(int i = 0; i < n; i++){
        prefix[i].first = 1LL * s[i] * pw[i].first % mod1;
        if(i)prefix[i].first = (1LL * prefix[i].first + prefix[i - 1].first) % mod1;
        prefix[i].second = 1LL * s[i] * pw[i].second % mod2;
        if(i)prefix[i].second = (1LL * prefix[i].second + prefix[i - 1].second) % mod2;
    }
}

pair<int, int> get_hash(int i, int j){
    assert(i <= j);
    pair<int, int> ans = {0, 0};
    ans.first = prefix[j].first;
    if(i) ans.first =  ((1LL * ans.first - prefix[i - 1].first) + mod1) % mod1;
    ans.first = 1LL * ans.first * ipw[i].first % mod1;
    ans.second = prefix[j].second;
    if(i) ans.second = ((1LL * ans.second - prefix[i - 1].second) + mod2) % mod2;
    ans.second = 1LL * ans.second * ipw[i].second % mod2;
    return ans;
}

pair<int, int> _hash(string &s){
    pair<int, int> ans = {0, 0};
    int n = (int) s.size();
    for(int i = 0; i < n; i++){
        ans.first = (1LL * ans.first +  1LL * s[i] * pw[i].first % mod1) % mod1;
        ans.second = (1LL * ans.second + 1LL * s[i] * pw[i].second % mod2) % mod2;
    }
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cal();
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        build(s);
        set<pair<int, int>> se;
        for(int i = 0; i + k - 1 < n; i++){
            se.insert(get_hash(i, i + k - 1));
        }
        cout << (int) se.size() << '\n';
    }
    return 0;
}
