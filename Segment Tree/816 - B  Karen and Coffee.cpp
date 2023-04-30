#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
int d[N], a[N], t[4 * N];

void build(int node, int b, int e) {
	if (b == e) {
		t[node] = a[b];
		return;
	}
	int m = (b + e) >> 1;
	build(2 * node, b, m);
	build(2 * node + 1, m + 1, e);
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
	int n, k, q;
	cin >> n >> k >> q;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		d[a] += 1;
		d[b + 1] -= 1;
	}
	for (int i = 1; i < N; i++) {
		d[i] += d[i - 1];
		if (d[i] >= k)a[i] = 1;
	}
	build(1, 1, N);
	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << query(1, 1, N, l, r) << '\n';
	}
	return 0;
}
