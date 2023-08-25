#include<bits/stdc++.h>
using namespace std;
using ll = long long;


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int w, f;
        cin >> w >> f;
        int n;
        cin >> n;
        int s = 0, a[n + 1];
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            s += a[i];
        }
        bool dp[n + 1][s + 1];
        memset(dp, false, sizeof dp);
        dp[0][0] = true;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= s; j++){
                dp[i][j] = dp[i - 1][j];
                if(j - a[i] >= 0)dp[i][j] |= dp[i - 1][j - a[i]];
            }
        }
        int ans = INT_MAX;
        for(int i = 0; i <= s; i++){
           if(dp[n][i]) ans = min(ans, max((i + w - 1) / w, (s - i + f - 1) / f));
        }
        cout << ans << '\n';
    }
    return 0;
}
