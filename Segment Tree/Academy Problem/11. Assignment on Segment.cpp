#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
int a[N], lazy[4 * N];; ll t[4 * N];

void push(int node, int b, int e) {
	if (lazy[node] == -1)return;
	t[node] = lazy[node];
	if (b != e) {
		lazy[2 * node] = lazy[node];
		lazy[2 * node + 1] = lazy[node];
	}
	lazy[node] = -1;
}

ll merge(int x, int y) {
	return 1LL * x + y;
}

void build(int node, int b, int e) {
	lazy[node] = -1;
	if (b == e) {
		t[node] = a[b];
		return;
	}
	int m = (b + e) >> 1;
	build(2 * node, b, m);
	build(2 * node + 1, m + 1, e);
	t[node] = merge(t[2 * node], t[2 * node + 1]);
}

void upd(int node, int b, int e, int l, int r, int v) {
	push(node, b, e);
	if (b > r or e < l)return;
	if (b >= l and e <= r) {
		lazy[node] = v;
		push(node, b, e);
		return;
	}
	int m = (b + e) >> 1;
	upd(2 * node, b, m, l, r, v);
	upd(2 * node + 1, m + 1, e, l, r, v);
	t[node] = merge(t[2 * node], t[2 * node + 1]);
}

ll query(int node, int b, int e, int l, int r) {
	push(node, b, e);
	if (b > r or e < l)return 0;
	if (b >= l and e <= r) {
		return t[node];
	}
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
	build(1, 1, n);
	while (q--) {
		int type;
		cin >> type;
		if (type == 1) {
			int l, r, v;
			cin >> l >> r >> v;
			r -= 1;
			l += 1, r += 1;
			upd(1, 1, n, l, r, v);
		} else {
			int i;
			cin >> i;
			i += 1;
			cout << query(1, 1, n, i, i) << '\n';
		}
	}
	return 0;
}
