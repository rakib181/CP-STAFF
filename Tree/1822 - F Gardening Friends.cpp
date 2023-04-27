#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 9;
vector<int> g[N]; int root, mx;
int d[N], r[N], m[N];

void dfs(int cur, int par) {
	for (auto x : g[cur]) {
		if (x != par) {
			d[x] = d[cur] + 1;
			dfs(x, cur);
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
	int tt;
	cin >> tt;
	while (tt--) {
		int n, k, c;
		cin >> n >> k >> c;
		for (int i = 0; i < n - 1; i++) {
			int u, v;
			cin >> u >> v;
			g[u].emplace_back(v);
			g[v].emplace_back(u);
		}
		root = 1, mx = 0;
		dfs(root, 0);
		for (int i = 1; i <= n; i++) {
			m[i] = d[i];
			if (d[i] >= mx) {
				mx = d[i];
				root = i;
			}
			d[i] = 0;
		}
		dfs(root, 0); mx = 0;
		for (int i = 1; i <= n; i++) {
			r[i] = d[i];
			if (d[i] >= mx) {
				mx = d[i];
				root = i;
			}
			d[i] = 0;
		}
		dfs(root, 0);
		ll ans = 0;
		for (int i = 1; i <= n; i++) {
			ll t = 1LL * max(d[i], r[i]) * k - 1LL * c * m[i];
			ans = max(ans, t);
		}
		cout << ans << '\n';
		for (int i = 0; i <= n; i++) {
			g[i].clear();
			d[i] = r[i] = m[i] = 0;
		}
	}
	return 0;
}
