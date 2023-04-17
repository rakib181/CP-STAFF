#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 9, inf = 1e9 + 7;
vector<tuple<int, int, bool>> g[N];
int n, m, k, d;

int dijkstra(int src, int dest) {
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
	vector<vector<int> > dist(12, vector<int> (n, inf));
	pq.push(make_tuple(0, src, 0));
	dist[0][src] = 0;
	int cnt = 0;
	while (!pq.empty()) {
		auto it = pq.top();
		int node = get<1> (it), cost = get<0> (it);
		pq.pop();
		if (node == dest)return dist[get<2> (it)][node];
		for (auto x : g[node]) {
			int cur_node = get<0> (x), cur_cost = get<1> (x);
			cnt = (get<2> (it)) + (get<2> (x));
			if (cnt <= d and cost + cur_cost <= dist[cnt][cur_node]) {
				dist[cnt][cur_node] = cost + cur_cost;
				pq.push(make_tuple(dist[cnt][cur_node], cur_node, cnt));
			}
		}
	}
	return -1;
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	auto start = clock();
	int tt, cs = 1;
	cin >> tt;
	while (tt--) {
		cout << "Case " << cs++ << ": ";
		cin >> n >> m >> k >> d;
		for (int i = 0; i < m; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			g[u].emplace_back(make_tuple(v, w, false));
		}
		for (int i = 0; i < k; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			g[u].emplace_back(make_tuple(v, w, true));
		}
		int YO = dijkstra(0, n - 1);
		if (YO != -1)cout << YO << '\n';
		else cout << "Impossible\n";
		for (int i = 0; i < n; i++) {
			g[i].clear();
		}
	}
	cerr << 1.0 * (clock() - start) / CLOCKS_PER_SEC << endl;
	return 0;
}
