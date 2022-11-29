#include <bits/stdc++.h>
using namespace std;

#define int long long int
const int mod = 1e9 + 7;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<char>> grid(n + 1, vector<char> (n + 1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> grid[i][j];
        }
    }
    vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
    dp[1][1] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(grid[i][j] == '.'){
                if(i > 1){
                    dp[i][j] += dp[i - 1][j];
                    dp[i][j] %= mod;
                }
                if(j > 1){
                    dp[i][j] += dp[i][j - 1];
                    dp[i][j] %= mod;
                }
            }
        }
    }
    cout << (grid[1][1] != '*' ? dp[n][n] : 0) << '\n';
    return 0;
}
