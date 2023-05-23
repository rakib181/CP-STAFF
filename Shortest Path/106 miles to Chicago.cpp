#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 105;
vector<pair<int, double>> g[N];
bitset<N> vis;

double dijkstra(int s, int d) {
    double dist[N];
    for (int i = 1; i <= d; i++) {
        dist[i] = 0.0;
    }
    priority_queue<pair<double, int>> pq;
    pq.push({ 1.0, s});
    dist[s] = 1.0;
    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        if (vis[node])continue;
        vis[node] = true;
        for (auto x : g[node]) {
            double ow = dist[node] * x.second;
            if (ow > dist[x.first]) {
                dist[x.first] = ow;
                pq.push({dist[x.first], x.first});
            }
        }
    }
    return dist[d];
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while (cin >> n and n) {
        int m;
        cin >> m;
        for (int i = 1; i <= n; i++)g[i].clear();
        for (int i = 1; i <= m; i++) {
            int u, v; double w;
            cin >> u >> v >> w;
            g[u].emplace_back(v, w / 100);
            g[v].emplace_back(u, w / 100);
        }
        cout << fixed << setprecision(6) <<  dijkstra(1, n) * 100 << " percent" << '\n';
        for(int i = 1; i <= n; i++)g[i].clear(), vis[i] = false;
    }
    return 0;
}
