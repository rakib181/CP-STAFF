#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 1e5 + 9, MOD = 1e9 + 7;
vector<int> g[N];
int dp[N][2];

void dfs(int cur, int par){
     dp[cur][0] = 1, dp[cur][1] = 1;
     for(auto x : g[cur]){
         if(x != par){
             dfs(x, cur);
             dp[cur][0] = ((dp[cur][0] % MOD) * (dp[x][0] + dp[x][1]) % MOD) % MOD;
             dp[cur][1] = ((dp[cur][1] % MOD) * (dp[x][0] % MOD)) % MOD;
         }
     }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    memset(dp, -1, sizeof dp);
    dfs(1, 0);
    cout << (dp[1][0] + dp[1][1]) % MOD << '\n';
    return 0;
}
