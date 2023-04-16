#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e4 + 9;
const ll inf = 1e15;
vector<pair<int, ll>> g[N];
vector<ll> dist(N, inf);

ll dijkstra(int src, int dest) {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    pq.push({0, src});
    dist[src] = 0;
    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        int node = it.second; ll cost = it.first;
        for (auto x : g[node]) {
            ll cur_w = x.second; int cur_node = x.first;
            if (cost + cur_w <= dist[cur_node]) {
                dist[cur_node] = cost + cur_w;
                pq.push({dist[cur_node], cur_node});
            }
        }
    }
    return dist[dest];
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    auto start = clock();
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < N; i++) {
            g[i].clear();
            dist[i] = inf;
        }
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            g[u].push_back({v, w});
        }
        int src, dest;
        cin >> src >> dest;
        ll dis = dijkstra(src, dest);
        if (dis != inf)cout << dis << '\n';
        else cout << "NO\n";
    }
    cerr << 1.0 * (clock() - start) / CLOCKS_PER_SEC << endl;
    return 0;
}
