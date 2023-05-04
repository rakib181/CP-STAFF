#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
int a[N];

struct lcs_left {
	int seg[4  * N];
	int merge(int x, int y) {
		return max(x, y);
	}
	void build(int node, int b, int e) {
		if (b == e) {
			seg[node] = 0;
			return;
		}
		int m = (b + e) >> 1;
		build(2 * node, b, m);
		build(2 * node + 1, m + 1, e);
		seg[node] = merge(seg[2 * node], seg[2 * node + 1]);
	}
	void upd(int node, int b, int e, int idx, int v) {
		if (b > idx or e < idx)return;
		if (b == e and b == idx) {
			seg[node] = v;
			return;
		}
		int m = (b + e) >> 1;
		upd(2 * node, b, m, idx, v);
		upd(2 * node + 1, m + 1, e, idx, v);
		seg[node] = merge(seg[2 * node], seg[2 * node + 1]);
	}

	int query(int node, int b, int e, int l, int r) {
		if (b > r or e < l) return 0;
		if (b >= l and e <= r)return seg[node];
		int m = (b + e) >> 1;
		return merge(query(2 * node, b, m, l, r), query(2 * node + 1, m + 1, e, l, r));
	}
} pref;

struct lcs_right {
	int seg[4  * N];
	int merge(int x, int y) {
		return max(x, y);
	}
	void build(int node, int b, int e) {
		if (b == e) {
			seg[node] = 0;
			return;
		}
		int m = (b + e) >> 1;
		build(2 * node, b, m);
		build(2 * node + 1, m + 1, e);
		seg[node] = merge(seg[2 * node], seg[2 * node + 1]);
	}
	void upd(int node, int b, int e, int idx, int v) {
		if (b > idx or e < idx)return;
		if (b == e and b == idx) {
			seg[node] = v;
			return;
		}
		int m = (b + e) >> 1;
		upd(2 * node, b, m, idx, v);
		upd(2 * node + 1, m + 1, e, idx, v);
		seg[node] = merge(seg[2 * node], seg[2 * node + 1]);
	}

	int query(int node, int b, int e, int l, int r) {
		if (b > r or e < l) return 0;
		if (b >= l and e <= r)return seg[node];
		int m = (b + e) >> 1;
		return merge(query(2 * node, b, m, l, r), query(2 * node + 1, m + 1, e, l, r));
	}
} suff;


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
		cout << "Case " << cs++ << ": ";
		int n;
		cin >> n; set<int> se;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			se.insert(a[i]);
		}
		pref.build(1, 1, N);
		suff.build(1, 1, N);
		map<int, int> mp; int id = 0;
		for (auto x : se) {
			mp[x] = ++id;
		}
		for (int i = 1; i <= n; i++) {
			a[i] = mp[a[i]];
		}
		int prefix[N], suffix[N];
		for (int i = 1; i <= n; i++) {
			prefix[i] = 1;
			if (a[i] != 1) {
				prefix[i] = max(prefix[i], pref.query(1, 1, N, 1, a[i] - 1) + 1);
			}
			pref.upd(1, 1, N, a[i], prefix[i]);
		}
		for (int i = n; i >= 1; i--) {
			suffix[i] = 1;
			if (a[i] != 1) {
				suffix[i] = max(suffix[i], suff.query(1, 1, N, 1, a[i] - 1) + 1);
			}
			suff.upd(1, 1, N, a[i], suffix[i]);
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			ans = max(ans, min(prefix[i], suffix[i]));
		}
		cout << 2 * ans - 1 << '\n';
	}
	return 0;
}
