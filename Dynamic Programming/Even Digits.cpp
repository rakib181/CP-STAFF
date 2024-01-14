#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    auto f = [&](ll v){
        string s = to_string(v);
        int sz = (int) s.size();
        vector<vector<ll>> dp(sz + 1, vector<ll> (2, -1));
        function<ll(int, int)> digdp = [&](int i, int is_smaller) -> ll{
             if(i == sz){
                 return 1;
             }
             if(dp[i][is_smaller] != -1)return dp[i][is_smaller];
             ll ans = 0;
             int d = (is_smaller ? 8 : s[i] - '0');
             for(int dig = 0; dig <= d; dig += 2){
                 ans += digdp(i + 1, is_smaller | (dig < (s[i] - '0')));
             }
            return dp[i][is_smaller] = ans;
        };
        return digdp(0, 0) >= n;
    };
    ll lo = 0, hi = 1e18, ans = 0;
    while(lo <= hi){
        ll m = (lo + hi) >> 1;
        if(f(m)){
            ans = m;
            hi = m - 1;
        }else lo = m + 1;
    }
    cout << ans << '\n';
    return 0;
}
