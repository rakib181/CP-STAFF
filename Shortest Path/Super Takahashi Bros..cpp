#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 9;
const ll inf = 1e16;
vector<pair<int, int>> g[N];
int n;

ll dijkstra(int src, int des) {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    vector<ll> dist(n + 1, inf);
    vector<bool> vis(n + 1, false);
    pq.emplace(0, src);
    dist[src] = 0;
    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        if (vis[it.second])continue;
        vis[it.second] = true;
        int node = it.second; ll cost = it.first;
        for (auto x : g[node]) {
            ll cur_w = x.second; int cur_node = x.first;
            if (cost + cur_w < dist[cur_node]) {
                dist[cur_node] = cost + cur_w;
                pq.emplace(dist[cur_node], cur_node);
            }
        }
    }
    return dist[des];
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i = 1; i < n; i++){
        int x, y, z;
        cin >> x >> y >> z;
        g[i].emplace_back(i + 1, x);
        g[i].emplace_back(z, y);
    }
    cout << dijkstra(1, n);
    return 0;
}
