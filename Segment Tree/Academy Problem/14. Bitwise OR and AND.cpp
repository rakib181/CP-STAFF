#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
int t[4 * N], lazy[4 * N];

void push(int node, int b, int e) {
	if (lazy[node] == 0)return;
	t[node] |= lazy[node];
	if (b != e) {
		lazy[2 * node] |= lazy[node];
		lazy[2 * node + 1] |= lazy[node];
	}
	lazy[node] = 0;
}

int merge(int x, int y) {
	return x & y;
}

void build(int node, int b, int e) {
	lazy[node] = 0;
	if (b == e) {
		t[node] = 0;
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

int query(int node, int b, int e, int l, int r) {
	push(node, b, e);
	if (b > r or e < l)return -1;
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
			int l, r;
			cin >> l >> r;
			r -= 1;
			l += 1, r += 1;
			cout << query(1, 1, n, l, r) << '\n';
		}
	}
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9, B = 30;
struct node {
	int AND[B];
};
node t[4 * N];
int lazy[4 * N];

node merge(node x, node y) {
	node ans;
	for (int i = 0; i < B; i++) {
		ans.AND[i] = x.AND[i] & y.AND[i];
	}
	return ans;
}

void push(int n, int b, int e) {
	if (lazy[n] == 0)return;
	for (int i = 0; i < B; i++) {
		if ((lazy[n] >> i) & 1) {
			t[n].AND[i] = 1;
		}
	}
	if (b != e) {
		lazy[2 * n] |= lazy[n];
		lazy[2 * n + 1] |= lazy[n];
	}
	lazy[n] = 0;
}

void build(int n, int b, int e) {
	lazy[n] = 0;
	if (b == e) {
		memset(t[n].AND, 0, sizeof t[n].AND);
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

node query(int n, int b, int e, int l, int r) {
	push(n, b, e);
	if (b > r or e < l) {
		node one;
		fill(one.AND, one.AND + B, 1);
		return one;
	}
	if (b >= l and e <= r) {
		return t[n];
	}
	int m = (b + e) >> 1;
	return merge(query(2 * n, b, m, l, r), query(2 * n + 1, m + 1, e, l, r));
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
			l += 1;
			upd(1, 1, n, l, r, v);
		} else {
			int l, r;
			cin >> l >> r;
			l += 1;
			node ans = query(1, 1, n, l, r);
			int f = 0;
			for (int i = 0; i < B; i++) {
				if (ans.AND[i]) {
					f |= (1 << i);
				}
			}
			cout << f << '\n';
		}
	}
	return 0;
}
