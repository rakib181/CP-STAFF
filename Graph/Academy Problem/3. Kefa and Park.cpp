#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
vector<int> g[N];
int n, m, ans = 0, a[N], consequtive[N];

void dfs(int cur, int par) {
	if (a[cur])consequtive[cur] = consequtive[par] + 1;
	else consequtive[cur] = 0;
	if (consequtive[cur] > m)return;
	bool leaf = true;
	for (auto x : g[cur]) {
		if (x != par) {
			dfs(x, cur);
			leaf = false;
		}
	}
	if (leaf) ans += 1;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n - 1; i++) {
		int u, v;
		cin >> u >> v;
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	dfs(1, 0);
	cout << ans << '\n';
	return 0;
}
