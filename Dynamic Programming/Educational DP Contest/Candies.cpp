#include <bits/stdc++.h>
using namespace std;
const int N = 105, MX = 1e5 + 9, MOD = 1e9 + 7;
int n, k, a[N], dp[N][MX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for(auto & i : dp){
        for(int j = 0; j < MX; j++){
            i[j] = 0;
        }
    }
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
            for(int v = 1; v <= k; v++){
                dp[i - 1][v] = 1LL * (1LL * dp[i - 1][v] + dp[i - 1][v - 1] % MOD) % MOD;
                dp[i - 1][v] %= MOD;
            }
            for(int v = 0; v <= k; v++){
                dp[i][v] = dp[i - 1][v];
               if(v - a[i] > 0) dp[i][v] = 1LL * (1LL * (1LL * (1LL *(1LL * dp[i][v] - dp[i - 1][v - a[i] - 1]) % MOD) + MOD) % MOD) % MOD;
            }
    }
    cout << dp[n][k];
    return 0;
}
