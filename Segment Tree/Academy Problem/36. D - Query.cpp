#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 3e4 + 9, MX = 2e5 + 9;
int a[N], t[4 * N], ans[MX];

void upd(int node, int b, int e, int i, int v) {
	if (b > i or e < i)return;
	if (b == e) {
		t[node] += v;
		return;
	}
	int m = (b + e) >> 1;
	upd(2 * node, b, m, i, v);
	upd(2 * node + 1, m + 1, e, i, v);
	t[node] = t[2 * node] + t[2 * node + 1];
}

int query(int node, int b, int e, int l, int r) {
	if (b > r or e < l)return 0;
	if (b >= l and e <= r)return t[node];
	int m = (b + e) >> 1;
	return query(2 * node, b, m, l, r) + query(2 * node + 1, m + 1, e, l, r);
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
		cin >> a[i];
	}
	int q;
	cin >> q; vector<pair<int, int>> Q[n + 1];
	for (int i = 1; i <= q; i++) {
		int l, r;
		cin >> l >> r;
		Q[r].push_back({l, i});
	}
	map<int, int> last_occ;
	for (int r = 1; r <= n; r++) {
		if (last_occ.find(a[r]) != last_occ.end()) {
			upd(1, 1, n, last_occ[a[r]], -1);
		}
		last_occ[a[r]] = r;
		upd(1, 1, n, last_occ[a[r]], 1);

		for (auto x : Q[r]) {
			ans[x.second] = query(1, 1, n, x.first, r);
		}
	}
	for (int i = 1; i <= q; i++) {
		cout << ans[i] << '\n';
	}
	return 0;
}
