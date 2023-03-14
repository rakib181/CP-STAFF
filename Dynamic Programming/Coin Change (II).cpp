#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int MOD =  100000007;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt, cs = 1;
    cin >> tt;
    while (tt--) {
        cout << "Case " << cs++ << ": ";
        int n, k;
        cin >> n >> k;
        vector<int> a(n + 1), dp(k + 2, 0);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                if (j - a[i] >= 0) {
                    dp[j] += dp[j - a[i]];
                    dp[j] %= MOD;
                }
            }
        }
        cout << dp[k] << '\n';
    }
    return 0;
}
