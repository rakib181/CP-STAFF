#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e6 + 9, p1 = 131, p2 = 151, mod1 = 2147483647, mod2 = 999999937;

int power(int x, int y, int mod){
    int ans = 1;
    while(y){
        if(y & 1) ans = 1LL * ans * x % mod;
        x = 1LL * x * x % mod;
        y >>= 1;
    }
    return ans;
}

int inv(int x, int mod){
    return power(x, mod - 2, mod);
}
pair<int, int> pw[N], ipw[N];

void cal(){
    pw[0] = {1, 1};
    for(int i = 1; i < N; i++){
        pw[i].first = 1LL * pw[i - 1].first * p1 % mod1;
        pw[i].second = 1LL * pw[i - 1].second * p2 % mod2;
    }
    ipw[0] = {1, 1};
    int ip1 = inv(p1, mod1);
    int ip2 = inv(p2, mod2);
    for(int i = 1; i < N; i++){
        ipw[i].first = 1LL * ipw[i - 1].first * ip1 % mod1;
        ipw[i].second = 1LL * ipw[i - 1].second * ip2 % mod2;
    }
}

pair<int, int> prefix[N];

void build(string &s){
    int n = (int) s.size();
    for(int i = 0; i < n; i++){
        prefix[i].first = 1LL * s[i] * pw[i].first % mod1;
        if(i) prefix[i].first = 1LL * (1LL * prefix[i].first + prefix[i - 1].first) % mod1;
        prefix[i].second = 1LL * s[i] * pw[i].second % mod2;
        if(i) prefix[i].second = 1LL * (1LL * prefix[i].second + prefix[i - 1].second) % mod2;
    }
}

pair<int, int> get_hash(int l, int r){
    pair<int, int> ans({0, 0});
    ans.first = prefix[r].first;
    if(l){
        ans.first = 1LL * ((1LL * ans.first - prefix[l - 1].first) % mod1 + mod1) % mod1;
        ans.first = 1LL * ans.first * ipw[l].first % mod1;
    }
    ans.second = prefix[r].second;
    if(l){
        ans.second = 1LL * ((1LL * ans.second - prefix[l - 1].second) % mod2 + mod2) % mod2;
        ans.second = 1LL * ans.second * ipw[l].second % mod2;
    }
    return ans;
}

pair<int, int> string_hash(string &s){
    int n = (int) s.size();
    pair<int, int> hs({0, 0});
    for(int i = 0; i < n; i++){
        hs.first = 1LL * (1LL * hs.first + 1LL * s[i] * pw[i].first % mod1) % mod1;
        hs.second = 1LL * (1LL * hs.second + 1LL * s[i] * pw[i].second % mod2) % mod2;
    }
    return hs;
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cal();
    string s;
    cin >> s;
    int n = (int) s.size();
    build(s);
    for(int len = 1; len <= n; len++){
        bool fine = true;
        auto p_hs = get_hash(0, len - 1);
        for(int i = 0; i < n; i += len){
            if(i + len - 1 >= n)break;
            auto s_sh = get_hash(i, i + len - 1);
            fine &= (p_hs == s_sh);
        }
        if(n % len){
            int l = n % len;
            auto f_h = get_hash(0, l - 1);
            auto s_h = get_hash(n - l, n - 1);
            fine &= (f_h == s_h);
        }
        if(fine){
            cout << len << ' ';
        }
    }
    return 0;
}