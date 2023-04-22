#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e4 + 9;
int a[N], b[N], Q[N], t[12 * N];

int merge(int x, int y) {
	return x + y;
}

void build(int node, int b, int e) {
	if (b == e) {
		t[node] = 0;
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
		t[node] += v;
		return;
	}
	int m = (b + e) >> 1;
	upd(2 * node, b, m, i, v);
	upd(2 * node + 1, m + 1, e, i, v);
	t[node] = merge(t[2 * node], t[2 * node + 1]);
}

int query(int node, int b, int e, int l, int r) {
	if (b > r or e < l)return 0;
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
	int tt, cs = 1;
	cin >> tt;
	while (tt--) {
		cout << "Case " << cs++ << ":\n";
		int n, q;
		cin >> n >> q;
		set<int> se;
		for (int i = 1; i <= n; i++) {
			cin >> a[i] >> b[i];
			se.insert(a[i]);
			se.insert(b[i]);
		}
		for (int i = 1; i <= q; i++) {
			cin >> Q[i];
			se.insert(Q[i]);
		}
		map<int, int> mp; int id = 0;
		for (auto x : se) {
			mp[x] = ++id;
		}
		for (int i = 1; i <= n; i++) {
			a[i] = mp[a[i]];
			b[i] = mp[b[i]];
		}
		for (int i = 1; i <= q; i++) {
			Q[i] = mp[Q[i]];
		}
		memset(t, 0, sizeof t);
		build(1, 1, id);
		for (int i = 1; i <= n; i++) {
			int l = a[i], r = b[i];
			upd(1, 1, id, l, 1);
			if (r + 1 <= id)upd(1, 1, id, r + 1, -1);
		}
		for (int i = 1; i <= q; i++) {
			int x = Q[i];
			cout << query(1, 1, id, 1, x) << '\n';
		}
	}
	return 0;
}
