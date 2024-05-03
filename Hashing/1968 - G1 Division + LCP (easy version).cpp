#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 9, p1 = 131, p2 = 151, mod1 = 2147483647, mod2 = 999999937;

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

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cal();
    int t;
    cin >> t;
    while(t--){
        int n, l, r;
        cin >> n >> l >> r;
        string s;
        cin >> s;
        build(s);
        auto f = [&](int len){
            auto hs = get_hash(0, len - 1);
            int i = len;
            int cnt = 1;
            while(i < n){
                if(i + len - 1 < n and hs == get_hash(i, i + len - 1)){
                    cnt += 1;
                    i += len;
                }else{
                    i += 1;
                }
            }
            return cnt >= l;
        };
        int L = 1, R = n, ans = 0;
        while(L <= R){
            int M = (L + R) >> 1;
            if(f(M)){
                ans = M;
                L = M + 1;
            }else{
                R = M - 1;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
