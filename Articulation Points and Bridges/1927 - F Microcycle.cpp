#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
struct edges{
    int u, v, w;
};
vector<vector<int>> g;
vector<int> low, tin;
int n, m, timer;
bool vis[N];
set<pair<int, int>> bridges;
vector<int> path;

void dfs(int u, int p){
    vis[u] = true;
    tin[u] = low[u] = ++timer;
    for(auto v : g[u]){
        if(v == p)continue;
        if(!vis[v]){
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] > tin[u]){
                bridges.insert({u, v});
                bridges.insert({v, u});
            }
        }else{
            low[u] = min(low[u], tin[v]);
        }
    }
}

void find_bridges(){
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            dfs(i, -1);
        }
    }
}
int root, dest;
bool cycle(int u, int p){
    vis[u] = true;
    if(u == dest){
        return true;
    }
    for(auto v : g[u]){
        if(v == p or bridges.count({u, v}) or vis[v])continue;
        path.emplace_back(v);
        if(cycle(v, u)){
            return true;
        }
        path.pop_back();
    }
    return false;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
        cin >> n >> m;
        g.resize(n + 1);
        low.resize(n + 1);
        tin.resize(n + 1);
        vector<edges> edge; timer = 0; path.clear();
        bridges.clear();
        for(int i = 1; i <= n; i++){
            g[i].clear();
            tin[i] = low[i] = 0;
            vis[i] = false;
        }
        for(int i = 1; i <= m; i++){
            int u, v, w;
            cin >> u >> v >> w;
            edge.push_back({u, v, w});
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
        find_bridges(); int min_weight = INT_MAX;
        for(auto [u, v, w] : edge){
            if(!bridges.count({u, v})){
                if(w < min_weight){
                    min_weight = w;
                    root = u;
                    dest = v;
                }
            }
        }
        path.emplace_back(root);
        for(int i = 1; i <= n; i++){
            vis[i] = false;
        }
        cycle(root, dest);
        cout << min_weight << ' ' << (int) path.size() << '\n';
        for(auto x : path){
            cout << x << ' ';
        }
        cout << '\n';
    }
    return 0;
}
