#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
vector<int> g[N];
int par[N], col[N]; bool found = false;

void dfs(int u) {
	if (found)return;
	col[u] = 1;
	for (auto x : g[u]) {
		if (found)return;
		if (col[x] == 0) {
			par[x] = u;
			dfs(x);
		} else if (col[x] == 1) {
			found = true;
			vector<int> path;
			path.emplace_back(x);
			int t = u;
			while (t != x) {
				path.emplace_back(t);
				t = par[t];
			}
			path.emplace_back(x);
			reverse(path.begin(), path.end());
			cout << (int) path.size() << '\n';
			for (auto xx : path) {
				cout << xx << ' ';
			}
			return;
		}
	}
	col[u] = 2;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		g[u].emplace_back(v);
	}
	for (int i = 1; i <= n; i++) {
		if (!found and !col[i]) {
			dfs(i);
		}
	}
	if (!found)cout << "IMPOSSIBLE\n";
	return 0;
}
