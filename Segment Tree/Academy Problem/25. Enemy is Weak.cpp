#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 9;
int a[N];

struct greater_ele {
	int t[4 * N];
	void upd(int node, int b, int e, int l, int r, int v) {
		if (b > r or e < l)return;
		if (b >= l and e <= r) {
			t[node] += v;
			return;
		}
		int m = (b + e) >> 1;
		upd(2 * node, b, m, l, r, v);
		upd(2 * node + 1, m + 1, e, l, r, v);
		t[node] = t[2 * node] + t[2 * node + 1];
	}

	int query(int node, int b, int e, int l, int r) {
		if (b > r or e < l)return 0;
		if (b >= l and e <= r)return t[node];
		int m = (b + e) >> 1;
		return query(2 * node, b, m, l, r) + query(2 * node + 1, m + 1, e, l, r);
	}
} g;

struct smaaller_ele {
	int t[4 * N];
	void upd(int node, int b, int e, int l, int r, int v) {
		if (b > r or e < l)return;
		if (b >= l and e <= r) {
			t[node] += v;
			return;
		}
		int m = (b + e) >> 1;
		upd(2 * node, b, m, l, r, v);
		upd(2 * node + 1, m + 1, e, l, r, v);
		t[node] = t[2 * node] + t[2 * node + 1];
	}

	int query(int node, int b, int e, int l, int r) {
		if (b > r or e < l)return 0;
		if (b >= l and e <= r)return t[node];
		int m = (b + e) >> 1;
		return query(2 * node, b, m, l, r) + query(2 * node + 1, m + 1, e, l, r);
	}
} s;


signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	set<int> se;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		se.insert(a[i]);
	}
	map<int, int> mp; int id = 0;
	for (auto x : se) {
		mp[x] = ++id;
	}
	for (int i = 1; i <= n; i++) {
		a[i] = mp[a[i]];
	}
	for (int i = 2; i <= n; i++) {
		s.upd(1, 1, id, a[i], a[i], 1);
	}
	g.upd(1, 1, id, a[1], a[1], 1);
	ll ans = 0;
	for (int i = 2; i < n; i++) {
		int x = g.query(1, 1, id, a[i] + 1, id);
		int y = s.query(1, 1, id, 1, a[i] - 1);
		s.upd(1, 1, id, a[i], a[i], -1);
		g.upd(1, 1, id, a[i], a[i], 1);
		ans += (1LL * x * y);
	}
	cout << ans << '\n';
	return 0;
}
