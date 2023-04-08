#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 9;
using ll = long long;
vector<int> g[N], rev[N], order, components, root_nodes;
vector<pair<int, int>> adj[N];
vector<bool> vis(N);
int n, m, s, t, C[N], R[N], COST[N];

void dfs(int cur){
    vis[cur] = true;
    for(auto x : g[cur]){
        if(!vis[x]){
            dfs(x);
        }
    }
    order.push_back(cur);
}

void DFS(int cur){
    vis[cur] = true;
    components.push_back(cur);
    for(auto x : rev[cur]){
        if(!vis[x]){
            DFS(x);
        }
    }
}

ll dijkstra(int src, int des){
    vector<long long> dist(n + 1, LONG_LONG_MAX);
    set<pair<long long, long long>> S;
    S.insert({-COST[src], src});
    while(!S.empty()){
        auto it = S.begin();
        long long node = it -> second;
        long long cur_dist = it -> first;
        S.erase(it);

        for(auto x : adj[node]){
            if(cur_dist + x.second < dist[x.first]){
                if(S.find({dist[x.first], x.first}) != S.end()){
                    S.erase({dist[x.first], x.first});
                }
                dist[x.first] = cur_dist + x.second;
                S.insert({dist[x.first], x.first});
            }
        }
    }
    return -1LL * dist[des];
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> s >> t;
    for(int i = 1; i <= n; i++){
        cin >> C[i];
    }
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        rev[v].push_back(u);
    }
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    vis.assign(n + 1, false);
    reverse(order.begin(), order.end());
    for(auto x : order){
        if(!vis[x]){
            components.clear();
            DFS(x);
            int root = components.back(), c = 0;
            for(auto xx : components){
                if(xx == s) root = s;
                if(xx == t) root = t;
            }
            for(auto xx : components)R[xx] = root, c += C[xx];
            root_nodes.push_back(root);
            COST[root] = c;
        }
    }
    for(int i = 1; i <= n; i++){
        for(auto x : g[i]){
            int root_v = R[i], root_u = R[x];
            if(root_v != root_u){
                adj[root_v].emplace_back(root_u, -COST[root_u]);
            }
        }
    }
    s = R[s], t = R[t];
    if(s == t){
        cout << COST[s] << '\n';
    }else cout << dijkstra(s, t) << '\n';
    return 0;
}
