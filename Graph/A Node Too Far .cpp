#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 65;
vector<int> g[N];
int d[N];

void bfs(int src) {
	d[src] = 0;
	queue<int> q;
	q.push(src);
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (auto x : g[node]) {
			if (d[node] + 1 < d[x]) {
				d[x] = d[node] + 1;
				q.push(x);
			}
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, cs = 1;
	while (cin >> n and n) {
		for (int i = 1; i < N; i++) {
			g[i].clear();
		}
		map<int, int> compressed, decompressed; set<int> se;
		vector<pair<int, int>> edges;
		for (int i = 0; i < n; i++) {
			int u, v;
			cin >> u >> v;
			edges.emplace_back(u, v);
			se.insert(u);
			se.insert(v);
		}
		int id = 0;
		for (auto x : se) {
			compressed[x] = ++id;
			decompressed[id] = x;
		}
		for (auto x : edges) {
			int u = compressed[x.first], v = compressed[x.second];
			g[u].emplace_back(v);
			g[v].emplace_back(u);
		}
		int root, dist;
		while (cin >> root >> dist and !(root == 0 and dist == 0)) {
			for (int i = 1; i <= id; i++) {
				d[i] = INT_MAX;
			}
			root = compressed[root];
			bfs(root);
			int c = 0;
			for (int i = 1; i <= id; i++) {
				if (d[i] > dist)c += 1;
			}
			cout << "Case " << cs++ << ": " << c << " nodes not reachable from node " << decompressed[root] << " with TTL = " << dist  << ".\n";
		}
	}
	return 0;
}
