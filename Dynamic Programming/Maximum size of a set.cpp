#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 2e5 + 9;
vector<int> g[N], DP(N);
vector<bool> vis(N);

void dfs(int cur){
    vis[cur] = true;
    DP[cur] = 1;
    for(auto x : g[cur]){
        if(!vis[x]) {
            dfs(x);
        }
        DP[cur] = max(DP[cur], DP[x] + 1);
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    for(int i = 1; i <= n; i++){
        if(!vis[i]) dfs(i);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans = max(ans, DP[i]);
    }
    cout << ans << '\n';
    return 0;
}
