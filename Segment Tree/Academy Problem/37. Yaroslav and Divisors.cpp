#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
int pos[N]; ll t[4 * N];
ll ans[N];
vector<int> valid[N];
vector<pair<int, int>> Q[N];

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

ll query(int node, int b, int e, int l, int r) {
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
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		pos[x] = i;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j += i) {
			int l = min(pos[i], pos[j]), r = max(pos[i], pos[j]);
			valid[r].push_back(l);
		}
	}
	for (int i = 1; i <= q; i++) {
		int l, r;
		cin >> l >> r;
		Q[r].push_back({l, i});
	}
	for (int r = 1; r <= n; r++) {
		for (auto l : valid[r]) {
			upd(1, 1, n, l, 1);
		}
		for (auto x : Q[r]) {
			ans[x.second] = query(1, 1, n, x.first, r);
		}
	}
	for (int i = 1; i <= q; i++) {
		cout << ans[i] << '\n';
	}
	return 0;
}
