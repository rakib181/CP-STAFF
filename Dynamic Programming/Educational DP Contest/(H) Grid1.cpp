#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 1005, MOD =  1e9 + 7; int n, m;
vector<vector<char>> grid(N, vector<char> (N));
int dp[N][N];
int dfs(int x, int y){
    if(x > n or y > m)return 0;
    if(x == n and y == m) return 1;
    if(dp[x][y] != -1) return dp[x][y];
    int ans = 0;
    if(grid[x + 1][y] != '#') ans = dfs(x + 1, y);
    if(grid[x][y + 1] != '#') ans += dfs(x, y + 1), ans %= MOD;
    return dp[x][y] = ans % MOD;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> grid[i][j];
        }
    }
    memset(dp, -1, sizeof dp);
    cout << dfs(1, 1) << '\n';
    return 0;
}
