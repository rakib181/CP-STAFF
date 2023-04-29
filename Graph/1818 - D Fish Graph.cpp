#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2005;
vector<int> g[N], path;
bool vis[N];
int active[N];

bool dfs(int cur, int root, int par) {
	if (vis[cur] or cur == par)return false;
	vis[cur] = true;
	path.push_back(cur);
	if (cur != root and active[cur]) {
		return true;
	}
	for (auto x : g[cur]) {
		if (dfs(x, root, par)) {
			return true;
		}
	}
	path.pop_back();
	return false;
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
		int n, m;
		cin >> n >> m;
		for (int i = 0; i <= n; i++) {
			g[i].clear();
		}
		path.clear();
		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		int f = 0;
		for (int i = 1; i <= n; i++) {
			if ((int)g[i].size() >= 4) {
				memset(vis, false, sizeof vis);
				memset(active, 0, sizeof active);
				for (auto x : g[i]) {
					active[x] = 1;
				}
				for (auto x : g[i]) {
					if (dfs(x, x, i)) {
						f = i;
						break;
					}
				}
			}
			if (f)break;
		}
		if (f) {
			cout << "YES\n" << (int) path.size() + 3 << '\n';
			cout << path[0] << ' ' << f << '\n';
			cout << path[(int) path.size() - 1] << ' ' << f << '\n';
			for (int i = 1; i < (int) path.size(); i++) {
				cout << path[i - 1] <<  ' ' << path[i] << '\n';
			}
			int cnt = 0;
			for (auto x : g[f]) {
				if (cnt == 2)break;
				if (x != path[0] and x != path[(int) path.size() - 1])cout << f << ' ' << x << '\n', cnt += 1;
			}
		} else cout << "NO\n";

	}
	return 0;
}
