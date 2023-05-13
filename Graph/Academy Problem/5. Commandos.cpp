#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 105, inf = 1e9 + 7;
vector<int> g[N];
int d[N], d1[N], d2[N];

void bfs(int s, int *dis) {
	queue<int> q;
	q.push(s);
	dis[s] = 0;
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (auto x : g[node]) {
			if (dis[node] + 1 < dis[x]) {
				dis[x] = dis[node] + 1;
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
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			g[i].clear();
			d[i] = inf;
		}
		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			u += 1, v += 1;
			g[u].emplace_back(v);
			g[v].emplace_back(u);
		}
		int s, e;
		cin >> s >> e;
		s += 1, e += 1;
		bfs(s, d);
		for (int i = 1; i <= n; i++) {
			d1[i] = d[i];
			d[i] = inf;
		}
		bfs(e, d);
		for (int i = 1; i <= n; i++) {
			d2[i] = d[i];
			d[i] = inf;
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			ans = max(ans, d1[i] + d2[i]);
		}
		cout << ans << '\n';
	}
	return 0;
}
