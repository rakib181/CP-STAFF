#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 105, NX = 1e5 + 9;
const ll inf = 1e15 + 9;
int x[N], y[N], z[N];
ll dp[N][NX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> x[i] >> y[i] >> z[i];
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < NX; j++){
            dp[i][j] = inf;
        }
    }
    dp[0][0] = 0;
    int s = accumulate(z + 1, z + n + 1, 0);
    for(int i = 1; i <= n; i++){
        ll need = max(0, ((x[i] + y[i]) / 2 + 1) - x[i]);
        for(int j = 0; j < NX; j++){
            dp[i][j] = dp[i - 1][j];
            if(j - z[i] >= 0)dp[i][j] = min(dp[i][j], dp[i - 1][j - z[i]] + need);
        }
    }
    ll ans = inf;
    for(int i = s / 2 + 1; i <= s; i++){
        ans = min(ans, dp[n][i]);
    }
    cout << ans << '\n';
    return 0;
}
