#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
int a[N], prefix[N], t[4 * N];

void build(int node, int b, int e) {
	if (b == e) {
		t[node] = prefix[b];
		return;
	}
	int m = (b + e) >> 1;
	build(2 * node, b, m);
	build(2 * node + 1, m + 1, e);
	t[node] = t[2 * node] + t[2 * node + 1];
}

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
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++)cin >> a[i];
	for (int i = 3; i <= n; i++) {
		if (a[i - 2] >= a[i - 1] and a[i - 1] >= a[i])prefix[i] = 1;
	}
	build(1, 1, n);
	while (q--) {
		int l, r;
		cin >> l >> r;
		if (prefix[l] == 1) {
			upd(1, 1, n, l, -1);
		}
		if (l + 1 <= n and prefix[l + 1] == 1) {
			upd(1, 1, n, l + 1, -1);
		}
		cout << (r - l + 1) - query(1, 1, n, l, r) << '\n';
		if (prefix[l] == 1) {
			upd(1, 1, n, l, 1);
		}
		if (l + 1 <= n and prefix[l + 1] == 1) {
			upd(1, 1, n, l + 1, 1);
		}
	}
	return 0;
}
