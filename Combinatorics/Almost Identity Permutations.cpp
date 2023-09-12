#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1005;
ll dp[N][5];

ll d(ll n){
    if(n == 1)return 0;
    if(n == 2)return 1;
    return (n - 1) * (d(n - 1) + d(n - 2));
}

ll nCr(ll n, ll r){
    if(n < r)return 0;
    if(r == 0)return 1;
    if(r == 1)return n;
    if(n == 1)return 1;
    if(dp[n][r] != -1)return dp[n][r];
    return dp[n][r] = nCr(n - 1, r - 1) + nCr(n - 1, r);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(dp, -1, sizeof dp);
    ll n, k;
    cin >> n >> k;
    ll ans = 1;
    for(ll i = 1; i <= k; i++){
        ans += nCr(n, i) * d(i);
    }
    cout << ans << '\n';
    return 0;
}
