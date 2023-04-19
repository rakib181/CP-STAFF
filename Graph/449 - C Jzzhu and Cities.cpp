#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
const ll inf = 1e15;
vector<pair<int, int>> g[N];
vector<int> ind(N, 0);
vector<pair<int , int>> edges;

int dijkstra(int src, int n) {
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	vector<ll> dist(n + 1, inf);
	bitset<N> vis;
	dist[src] = 0;
	pq.push({0, src});
	while (!pq.empty()) {
		auto it = pq.top();
		pq.pop();
		int node = it.second; ll cost = it.first;
		if (vis[node])continue;
		vis[node] = true;
		for (auto x : g[node]) {
			int cur_node = x.first, cur_cost = x.second;
			if (cost + cur_cost < dist[cur_node]) {
				dist[cur_node] = cost + cur_cost;
				ind[cur_node] = 1;
				pq.push({dist[cur_node], cur_node});
			} else if (cost + cur_cost == dist[cur_node]) {
				ind[cur_node] += 1;
			}
		}
	}
	int cnt = 0;
	for (auto x : edges) {
		if (dist[x.first] < x.second) {
			cnt += 1;
		} else if (dist[x.first] == x.second) {
			if (ind[x.first] > 1) {
				ind[x.first] -= 1;
				cnt += 1;
			}
		}
	}
	return cnt;
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	auto start = clock();
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].emplace_back(v, w);
		g[v].emplace_back(u, w);
	}
	for (int i = 0; i < k; i++) {
		int s, w;
		cin >> s >> w;
		g[1].emplace_back(s, w);
		edges.emplace_back(s, w);
	}
	cout << dijkstra(1, n) << '\n';
	cerr << 1.0 * (clock() - start) / CLOCKS_PER_SEC << endl;
	return 0;
}
