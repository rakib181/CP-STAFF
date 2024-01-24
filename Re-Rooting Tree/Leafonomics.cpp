#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 9;
const ll inf = 1e16 + 9;
int n; vector<pair<int, int>> g[N];
ll dp[N], ans[N], up[N];
int tme, in[N], ou[N];

void dfs(int u, int p){
    in[u] = ++tme;
    for(auto [v, w] : g[u]){
        if(v != p){
            dfs(v, u);
            dp[u] = min(dp[u], dp[v] + w);
        }
    }
    ou[u] = tme;
    if(u != 1 and (int) g[u].size() == 1) {
        dp[u] = 0;
    }
}

void cal(int u, int p, int cost){
     if(p != 0){
         up[p] = inf;
         for(auto [v, w] : g[p]){
             if(v == u)continue;
             if(in[v] < in[p] and ou[v] >= ou[p]){
                 up[p] = min(up[p], up[v] + w);
             }else{
                 up[p] = min(up[p], dp[v] + w);
             }
         }
         ans[u] = min(dp[u], up[p] + cost);
     }
     for(auto [v, w] : g[u]){
         if(v != p){
             cal(v, u, w);
         }
     }
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        cin >> n; tme = 0;
        for(int i = 1; i <= n; i++){
            g[i].clear();
            dp[i] = inf;
            in[i] = ou[i] = 0;
            ans[i] = 0;
            up[i] = inf;
        }
        for(int i = 1; i < n; i++){
            int u, v, w;
            cin >> u >> v >> w;
            g[u].emplace_back(v, w);
            g[v].emplace_back(u, w);
        }
        dfs(1, -1);
        ans[1] = dp[1];
        cal(1, 0, 0);
        for(int i = 1; i <= n; i++){
            cout << ans[i] << " \n"[i == n];
        }
    }
    return 0;
}
