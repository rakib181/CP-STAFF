#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 4e5 + 9;
vector<bool> vis(N);
vector<int> comp(N), top;
vector<int> dp(N), cycle(N);

void dfs(int u, vector<int> *g){
    vis[u] = true;
    for(auto v : g[u]){
        if(!vis[v]){
            dfs(v, g);
        }
    }
    top.emplace_back(u);
}


void dfs2(int u,int c, vector<int> *g){
    comp[u] = c;
    for(auto v : g[u]){
        if(!comp[v]){
            dfs2(v, c, g);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<int> g[n + 1], rev_g[n + 1]; top.clear();
        vector<pair<int, int>> edge;
        for(int i = 1; i <= n; i++){
           dp[i] = comp[i] = cycle[i] = 0;
           vis[i] = false;
        }
        for (int i = 1; i <= m; i++) {
            int u, v;
            cin >> u >> v;
            g[u].emplace_back(v);
            rev_g[v].emplace_back(u);
            edge.emplace_back(u, v);
        }
        for(int i = 1; i <= n; i++){
            if(!vis[i]){
                dfs(i, g);
            }
        }
        reverse(top.begin(), top.end());
        int cnt = 0;
        for (auto v: top) {
            if (!comp[v]) {
                dfs2(v, ++cnt, rev_g);
            }
        }
        for(auto [u, v] : edge){
            if(comp[u] == comp[v])cycle[comp[u]] = 1;
        }
        vector<int> condense[n + 1];
        for (int u = 1; u <= n; u++) {
            for (auto v: g[u]) {
                if (comp[u] != comp[v]) {
                    condense[comp[u]].emplace_back(comp[v]);
                }
            }
        }
        dp[comp[1]] = 1;
        for(int i = 1; i <= cnt; i++){
            if(dp[i] > 0 and cycle[i])dp[i] = -1;
            if(dp[i] != 0){
                for(auto v : condense[i]){
                    if(dp[i] == -1)dp[v] = -1;
                    else if(dp[v] != -1){
                        dp[v] += dp[i];
                    }
                    if(dp[v] > 1)dp[v] = 2;
                }
            }
        }
        for(int i = 1; i <= n; i++){
            cout << dp[comp[i]] << " \n"[i == n];
        }
    }
    return 0;
}
