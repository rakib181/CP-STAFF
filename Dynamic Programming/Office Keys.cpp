#include<bits/stdc++.h>
using namespace  std;
#define int long long int
const int N = 2005, inf = 1e17;
int dp[N][N];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k, p;
    cin >> n >> k >> p;
    int a[n], b[k];
    for(int i = 0; i < n; i++)cin >> a[i];
    for(int i = 0; i < k; i++)cin >> b[i];
    sort(a, a + n), sort(b, b + k);
    for(int i = 0; i <= k; i++){
        for(int j = 0; j <= n; j++){
            dp[i][j] = inf;
        }
    }
    dp[0][0] = 0;
    for(int i = 0; i <= k; i++){
        for(int j = 0; j <= n; j++){
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
            if(j < n) dp[i + 1][j + 1] = min(dp[i + 1][j + 1], max(dp[i][j], abs(a[j] - b[i]) + abs(b[i] - p)));
        }
    }
    cout << dp[k][n] << '\n';
    return 0;
}
