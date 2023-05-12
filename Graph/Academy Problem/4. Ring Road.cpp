#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 105;
vector<pair<int, int >> g[N];
bool vis[N];
int cost, sum;

void dfs(int cur, int par) {
	vis[cur] = true;
	for (auto x : g[cur]) {
		if (!vis[x.first]) {
			cost += x.second;
			dfs(x.first, cur);
		} else if (x.first != par and x.first == 1) {
			cost += x.second;
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
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].emplace_back(v, 0);
		g[v].emplace_back(u, w);
		sum += w;
	}
	dfs(1, -1);
	cout << min(cost, sum - cost) << '\n';
	return 0;
}
