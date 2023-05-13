#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1005, inf = 1e9;
vector<int> g[N];
int d[N];

void bfs(int s) {
	int dist[N];
	for (int i = 1; i < N; i++)dist[i] = inf;
	queue<int> q;
	q.push(s);
	dist[s] = 0;
	d[s] += 1;
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (auto x : g[node]) {
			if (dist[node] + 1 < dist[x]) {
				d[x] += 1;
				dist[x] = dist[node] + 1;
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
	int t, cs = 1;
	cin >> t;
	while (t--) {
		cout << "Case " << cs++ << ": ";
		int k, n, m;
		cin >> k >> n >> m;
		for (int i = 1; i <= n; i++) {
			g[i].clear();
			d[i] = 0;
		}
		vector<int> nodes;
		for (int i = 0; i < k; i++) {
			int x;
			cin >> x;
			nodes.push_back(x);
		}
		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
		}
		for (auto s : nodes) {
			bfs(s);
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (d[i] >= k)ans += 1;
		}
		cout << ans << '\n';
	}
	return 0;
}
