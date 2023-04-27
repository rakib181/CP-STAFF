#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 9;
int n, a[N], p[N], t[4 * N];

void build(int node, int b, int e) {
	if (b == e) {
		t[node] = 1;
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

int Q(int x) {
	int l = 1, r = n, idx = n + 1;
	while (l <= r) {
		int m = (l + r) >> 1;
		int val = query(1, 1, n, m, n);
		if (val == x) {
			idx = m;
			r = m - 1;
		}
		if (val > x) {
			l = m + 1;
		} else r = m - 1;
	}
	return idx;
}



signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	build(1, 1, n);
	for (int i = n; i >= 1; i--) {
		int x = Q(a[i]);
		p[i] = x - 1;
		upd(1, 1, n, p[i], -1);
	}
	for (int i = 1; i <= n; i++) {
		cout << p[i] << ' ';
	}
	return 0;
}
