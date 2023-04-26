#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e7 + 9;
int a[N], t[4 * N];

void build(int node, int b, int e) {
	if (b == e) {
		t[node] = 0;
		return;
	}
	int m = (b + e) >> 1;
	build(2 * node, b, m);
	build(2 * node + 1, m + 1, e);
	t[node] = t[2 * node] + t[2 * node + 1];
}

void upd(int node, int b, int e, int l, int r, int v) {
	if (b > r or e < l)return;
	if (b >= l and e <= r) {
		t[node] = v;
		return;
	}
	int m = (b + e) >> 1;
	upd(2 * node, b, m, l, r, v);
	upd(2 * node + 1, m + 1, e, l, r, v);
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
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		build(1, 1, N);
		ll ans = 0;
		for (int i = n; i >= 1; i--) {
			ans += query(1, 1, N, 1, a[i] - 1);
			upd(1, 1, N, a[i], a[i], 1);
		}
		cout << ans << '\n';
	}
	return 0;
}
