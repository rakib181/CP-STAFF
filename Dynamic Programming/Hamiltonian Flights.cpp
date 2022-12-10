#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 25, mod = 1e9 + 7;
vector<int> g[N];
int dp[N][(1 << 20)];
int n, m;

int dfs(int cur, int mask){
    if(__builtin_popcount(mask) == n)return 1;
    else if(cur == n - 1)return 0;
    if(dp[cur][mask] != -1)return dp[cur][mask];
    int res = 0;
    for(auto x : g[cur]){
        if(mask & (1 << x))continue;
        res = (res + dfs(x, mask | (1 << x))) % mod;
    }
    return dp[cur][mask] = res % mod;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        g[--u].push_back(--v);
    }
    memset(dp, -1, sizeof dp);
    cout << dfs(0, 1) << '\n';
    return 0;
}
