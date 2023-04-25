#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
struct node {
	int mod_under_3[3];
};

node t[4 * N];
int lazy[4 * N];

node merge(node x, node y) {
	node ans;
	for (int i = 0; i < 3; i++) {
		ans.mod_under_3[i] = (x.mod_under_3[i] + y.mod_under_3[i]);
	}
	return ans;
}

void push(int n, int b, int e) {
	if (lazy[n] == 0)return;
	node cur = t[n];
	for (int i = 0; i < 3; i++) {
		t[n].mod_under_3[(i + lazy[n]) % 3] = cur.mod_under_3[i];
	}
	if (b != e) {
		lazy[2 * n] = (lazy[2 * n] + lazy[n]) % 3;
		lazy[2 * n + 1] = (lazy[2 * n + 1] + lazy[n]) % 3;
	}
	lazy[n] = 0;
}

void build(int n, int b, int e) {
	lazy[n] = 0;
	if (b == e) {
		t[n].mod_under_3[0] = 1;
		t[n].mod_under_3[1] = 0;
		t[n].mod_under_3[2] = 0;
		return;
	}
	int m = (b + e) >> 1;
	build(2 * n, b, m);
	build(2 * n + 1, m + 1, e);
	t[n] = merge(t[2 * n], t[2 * n + 1]);
}

void upd(int n, int b, int e, int l, int r, int v) {
	push(n, b, e);
	if (b > r or e < l)return;
	if (b >= l and e <= r) {
		lazy[n] = v;
		push(n, b, e);
		return;
	}
	int m = (b + e) >> 1;
	upd(2 * n, b, m, l, r, v);
	upd(2 * n + 1, m + 1, e, l, r, v);
	t[n] = merge(t[2 * n], t[2 * n + 1]);
}

int query(int n, int b, int e, int l, int r) {
	push(n, b, e);
	if (b > r or e < l)return 0;
	if (b >= l and e <= r) {
		return t[n].mod_under_3[0];
	}
	int m = (b + e) >> 1;
	return query(2 * n, b, m, l, r) + query(2 * n + 1, m + 1, e, l, r);
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
			if (type == 0) {
				int l, r;
				cin >> l >> r;
				upd(1, 0, n - 1, l, r, 1);
			} else {
				int l, r;
				cin >> l >> r;
				cout << query(1, 0, n - 1, l, r) << '\n';
			}
		}
	}
	return 0;
}
