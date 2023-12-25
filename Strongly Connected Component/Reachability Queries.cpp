#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e4 + 9;
vector<bool> vis(N);
vector<int> comp(N), top;

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


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> g[n + 1], rev_g[n + 1];
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        rev_g[v].emplace_back(u);
    }
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            dfs(i, g);
        }
    }
    reverse(top.begin(), top.end());
    int cnt = 0;
    for(auto v : top){
        if(!comp[v]){
            dfs2(v, ++cnt, rev_g);
        }
    }
    vector<int> condense[n + 1];
    for(int u = 1; u <= n; u++){
        for(auto v : g[u]){
            if(comp[u] != comp[v]){
                condense[comp[u]].emplace_back(comp[v]);
            }
        }
    }
    vis.assign(n + 1, false);
    top.clear();
    for(int i = 1; i <= cnt; i++){
        if(!vis[i]){
            dfs(i, condense);
        }
    }
    vector<bitset<N>> dp(cnt + 1);
    for(auto u : top){
        dp[u].set(u);
        for(auto v : condense[u]){
            dp[u] |= dp[v];
        }
    }
    while(q--){
        int x, y;
        cin >> x >> y;
        if(dp[comp[x]][comp[y]]){
            cout << "YES\n";
        }else cout << "NO\n";
    }
    return 0;
}
