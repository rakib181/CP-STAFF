#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9, inf = 1e9 + 7;
int a[N], t[4 * N];

int merge(int x, int y) {
	return min(x, y);
}

void build(int node, int b, int e) {
	if (b == e) {
		t[node] = a[b];
		return;
	}
	int m = (b + e) >> 1;
	build(2 * node, b, m);
	build(2 * node + 1, m + 1, e);
	t[node] = merge(t[2 * node], t[2 * node + 1]);
}

void upd(int node, int b, int e, int i, int v) {
	if (b > i or e < i)return;
	if (b == e) {
		t[node] = v;
		return;
	}
	int m = (b + e) >> 1;
	upd(2 * node, b, m, i, v);
	upd(2 * node + 1, m + 1, e, i, v);
	t[node] = merge(t[2 * node], t[2 * node + 1]);
}
int query(int node, int b, int e, int l, int r) {
	if (b > r or e < l)return inf;
	if (b >= l and e <= r)return t[node];
	int m = (b + e) >> 1;
	return merge(query(2 * node, b, m, l, r), query(2 * node + 1, m + 1, e, l, r));
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
		cin >> a[i];
	}
	build(1, 1, n);
	while (q--) {
		int type;
		cin >> type;
		if (type == 1) {
			int i, v;
			cin >> i >> v;
			i += 1;
			upd(1, 1, n, i, v);
		} else {
			int l, r;
			cin >> l >> r;
			l += 1;
			cout << query(1, 1, n, l, r) << '\n';
		}
	}
	return 0;
}
