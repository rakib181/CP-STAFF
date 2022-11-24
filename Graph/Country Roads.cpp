#include <bits/stdc++.h>
using namespace std;
const int N = 509;
vector<vector<int>> cost(N, vector<int> (N));
vector<int> g[N];

void dijkstra(int src, int n){
    vector<int> dist(n + 1, INT_MAX);
    set<int> q;
    dist[src] = 0;
    q.insert(src);
    while (!q.empty()){
        auto it = q.begin();
        int node = *it;
        q.erase(it);
        for(int i = 0; i < (int) g[node].size(); i++){
            int cur_city = g[node][i];
            int mx_cost = max(dist[node], cost[node][cur_city]);
            if(dist[cur_city] > mx_cost){
                if(q.find(cur_city) != q.end()){
                    q.erase(cur_city);
                }
                dist[cur_city] = mx_cost;
                q.insert(cur_city);
            }
        }
    }
    for(int i = 0;  i < n; i++){
        if(dist[i] != INT_MAX)cout << dist[i] << '\n';
        else cout << "Impossible" << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt, idx = 1;
    cin >> tt;
    while (tt--) {
        cout << "Case " << idx++ << ":" << '\n';
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < N; i++){
            g[i].clear();
            for(int j = 0; j < N; j++){
                cost[i][j] = 0;
            }
        }
        for (int i = 0; i < m; i++) {
            int u, v, wt;
            cin >> u >> v >> wt;
            if (!cost[u][v]) {
                g[u].push_back(v);
                g[v].push_back(u);
                cost[u][v] = wt;
                cost[v][u] = wt;
            } else cost[u][v] = min(cost[u][v], wt), cost[v][u] = min(cost[v][u], wt);
        }
        int src;
        cin >> src;
        dijkstra(src, n);
    }
    return 0;
}
