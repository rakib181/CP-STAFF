#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        int a[n + 1];
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        ll dp[n + 1][n + 2];
        memset(dp, 0, sizeof dp);
        dp[1][0] = max(0LL, 1LL * a[1]);
        dp[1][1] = max(0LL, 1LL * a[1] + x);
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= i + 1; j++){
                dp[i][j] = max(0LL, dp[i - 1][j] + a[i]);
                if(j) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + a[i] + x);
            }
        }
        ll mx = 0;
        for(int j = 0; j <= n; j++){
            for(int i = 1; i <= n; i++){
                mx = max(mx, dp[i][j]);
            }
            cout << mx << ' ';
        }
        cout << '\n';
    }
    return 0;
}
