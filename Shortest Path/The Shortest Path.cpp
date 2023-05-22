#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e4 + 9;
const ll inf = 1e12;
vector<pair<int, ll>> g[N];
vector<ll> dist(N, inf);
bitset<N> vis;

ll dijkstra(int src, int des) {
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
	pq.push({0, src});
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
				pq.push({dist[cur_node], cur_node});
			}
		}
	}
	return dist[des];
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)g[i].clear();
		map<string, int> city;
		for (int i = 1; i <= n; i++) {
			string s;
			cin >> s;
			city[s] = i;
			int m;
			cin >> m;
			while (m--) {
				int u, c;
				cin >> u >> c;
				g[i].emplace_back(u, c);
				g[u].emplace_back(i, c);
			}
		}
		int q;
		cin >> q;
		while (q--) {
			string src, des;
			cin >> src >> des;
			int s = city[src], d = city[des];
			for (int i = 1; i <= n; i++) {
				dist[i] = inf;
				vis[i] = false;
			}
			cout << dijkstra(s, d) << '\n';
		}
	}
	return 0;
}
