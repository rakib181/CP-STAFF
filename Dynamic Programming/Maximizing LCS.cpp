#include<bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--){
      int n;
      cin >> n;
      string s, t;
      cin >> s;
        t = s;
        s = '$' + s;
        reverse(t.begin(), t.end());
        t = '$' + t;
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                dp[i][j] = max({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] + (s[i] == t[j])});
            }
        }
       cout << dp[n][n] / 2 << '\n';
    }
    return 0;
}
