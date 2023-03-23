#include<bits/stdc++.h>
using namespace  std;
#define int long long int
const int inf = 5e18, cost = 1e12;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--){
        string s;
        cin >> s;
        int n = (int) s.size();
        vector<array<int, 2>> dp(n + 1, {inf, inf});
        dp[0][0] = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 2; j++){
               if(s[i] - '0' >= j) dp[i + 1][s[i] - '0'] = min(dp[i + 1][s[i] - '0'], dp[i][j]);
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + cost + 1);
                if(i + 1 < n and j <= (s[i + 1] - '0') and (s[i] - '0') >= (s[i + 1] - '0')){
                    dp[i + 2][s[i] - '0'] = min(dp[i + 2][s[i] - '0'], dp[i][j] + cost);
                }
            }
        }
        cout << min(dp[n][0], dp[n][1]) << '\n';
    }
    return 0;
}
