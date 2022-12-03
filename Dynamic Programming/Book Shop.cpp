#include <bits/stdc++.h>
using namespace std;


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;
    cin >> n >> x;
    vector<int> price(n + 1), pages(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> price[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> pages[i];
    }
    vector<vector<int>> dp(n + 2, vector<int> (x + 2, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= x; j++){
            dp[i][j] = dp[i - 1][j];
            if(j - price[i] >= 0){
                dp[i][j] = max(dp[i][j], dp[i - 1][j - price[i]] + pages[i]);
            }
        }
    }
    cout << dp[n][x] << '\n';
    return 0;
}
