#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
vector<int> g[N], ind_set[N];
bool found, vis[N];
int required_node, par[N], dep[N], col[N];

void dfs(int u, int p) {
	if (found)return;
	vis[u] = true;
	dep[u] = dep[p] + 1;
	par[u] = p;
	for (auto x : g[u]) {
		if (found)return;
		if (!vis[x]) {
			dfs(x, u);
		} else if (x != p) {
			int d = dep[u] - dep[x] + 1;
			if (d >= required_node) {
				found = true;
				cout << "2\n" << d << '\n';
				while (u != x) {
					cout << u << ' ';
					u = par[u];
				}
				cout << u << ' ' <<  '\n';
				return;
			}
		}
	}
}

void color(int u) {
	vis[u] = true;
	for (auto x : g[u]) {
		if (!vis[x]) {
			color(x);
		}
	}
	set<int> not_allowed;
	for (auto x : g[u]) {
		if (col[x])not_allowed.insert(col[x]);
	}
	int s = 1;
	while (not_allowed.find(s) != not_allowed.end())++s;
	col[u] = s;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	cin >> n >> m; found = false;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	int k = 1;
	while (k * k < n) ++k;
	required_node = k;
	dfs(1, 0);
	if (found)return 0;
	memset(vis, false, sizeof vis);
	color(1);
	for (int i = 1; i <= n; i++) {
		ind_set[col[i]].emplace_back(i);
	}
	for (int i = 1; i <= n; i++) {
		if ((int) ind_set[i].size() >= required_node) {
			cout << "1\n";
			for (int j = 0; j < required_node; j++) {
				cout << ind_set[i][j] << ' ';
			}
			cout << '\n';
			return 0;
		}
	}
	return 0;
}
