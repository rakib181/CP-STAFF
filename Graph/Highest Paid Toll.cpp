#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e4 + 9;
const int inf = 1e9 + 7;

vector<int> dijkstra(int src, int n, vector<vector<pair<int, int>>> &g) {
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	vector<int> dist(n + 1, inf);
	bitset <N> vis;
	pq.push({0, src});
	dist[src] = 0;
	while (!pq.empty()) {
		auto it = pq.top();
		pq.pop();
		int node = it.second; int cost = it.first;
		if (vis[node])continue;
		vis[node] = true;
		for (auto x : g[node]) {
			int cur_node = x.first; int cur_cost = x.second;
			if (cost + cur_cost <= dist[cur_node]) {
				dist[cur_node] = cost + cur_cost;
				pq.push({dist[cur_node], cur_node});
			}
		}
	}
	return dist;
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
		int n, m, s, t, p;
		cin >> n >> m >> s >> t >> p;
		queue<tuple<int, int, int >> edges;
		vector < vector<pair<int, int>>> g(n + 1, vector < pair<int, int>> ()), rg(n + 1, vector<pair<int, int>> ());
		for (int i = 0; i < m; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			g[u].emplace_back(v, w);
			rg[v].emplace_back(u, w);
			edges.push(make_tuple(u, v, w));
		}
		vector<int> dist_ori = dijkstra(s, n, g);
		vector<int> dist_rev = dijkstra(t, n, rg);
		int best = -1;
		while (!edges.empty()) {
			tuple<int, int, int> x = edges.front();
			edges.pop();
			if (dist_ori[get<0> (x)] + get<2> (x) + dist_rev[get<1> (x)] <= p) {
				best = max(best, get<2> (x));
			}
		}
		cout << best << '\n';
	}
	cerr << 1.0 * (clock() - start) / CLOCKS_PER_SEC << endl;
	return 0;
}
