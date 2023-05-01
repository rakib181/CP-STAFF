#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
int t[4 * N];
int lazy[4 * N];

void push(int node, int b, int e) {
	if (lazy[node] == -1)return;
	t[node] = (e - b + 1) * lazy[node];
	if (b != e) {
		lazy[2 * node] = lazy[node];
		lazy[2 * node + 1] = lazy[node];
	}
	lazy[node] = -1;
}

void build(int node, int b, int e) {
	lazy[node] = -1;
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
	t[node] = t[2 * node] + t[2 * node + 1];
}

int query(int node, int b, int e, int l, int r) {
	push(node, b, e);
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
	int t, cs = 1;
	cin >> t;
	while (t--) {
		cout << "Case " << cs++ << ":\n";
		int n, q;
		cin >> n >> q;
		build(1, 0, n - 1);
		while (q--) {
			int type;
			cin >> type;
			if (type == 1) {
				int l, r, v;
				cin >> l >> r >> v;
				upd(1, 0, n - 1, l, r, v);
			} else {
				int l, r;
				cin >> l >> r;
				int ans = query(1, 0, n - 1, l, r);
				int g = __gcd(ans, (r - l + 1));
				if (ans % (r - l + 1))cout << ans / g << '/' << (r - l + 1) / g << '\n';
				else cout << ans / g << '\n';
			}
		}
	}
	return 0;
}
