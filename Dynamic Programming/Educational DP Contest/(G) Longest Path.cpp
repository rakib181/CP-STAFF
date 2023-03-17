#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 1e5 + 9;
vector<int> g[N];
int dp[N];

int dfs(int cur){
    if(dp[cur] != -1)return dp[cur];
    int ans = 0;
    for(auto x : g[cur]){
        ans = max(ans, dfs(x) + 1);
    }
    return dp[cur] = ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    memset(dp, -1, sizeof dp);
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans = max(ans, dfs(i));
    }
    cout << ans << '\n';
    return 0;
}
