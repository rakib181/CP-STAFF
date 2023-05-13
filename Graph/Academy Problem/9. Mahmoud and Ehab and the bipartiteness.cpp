#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define R 1
#define B 2
#define E 0
const int N = 1e5 + 9;
vector<int> g[N];
int black = 0, white = 0, col[N];

void dfs(int u) {
	if (col[u] == R)black += 1;
	if (col[u] == B)white += 1;
	for (auto x : g[u]) {
		if (col[x] == E) {
			col[x] = (col[u] == R) ? B : R;
			dfs(x);
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
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	for (int i = 1; i <= n; i++)col[i] = E;
	col[1] = R;
	dfs(1);
	ll ans = 1LL * white * black - n + 1;
	cout << ans << '\n';
	return 0;
}
