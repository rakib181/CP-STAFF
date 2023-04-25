#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9, inf = 1e9 + 7;
int a[N];


struct seg_gcd {
	int t[4 * N];
	int merge(int x, int y) {
		return __gcd(x, y);
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
	int query(int node, int b, int e, int l, int r) {
		if (b > r or e < l)return 0;
		if (b >= l and e <= r)return t[node];
		int m = (b + e) >> 1;
		return merge(query(2 * node, b, m, l, r), query(2 * node + 1, m + 1, e, l, r));
	}
} s1;

struct seg_min {
	pair<int, int> t[4 * N];
	pair<int, int> merge(pair<int , int> x, pair<int, int> y) {
		if (x.first < y.first) {
			return x;
		} else if (x.first > y.first) {
			return y;
		} else {
			return {x.first, x.second + y.second};
		}
	}
	void build(int node, int b, int e) {
		if (b == e) {
			t[node] = {a[b], 1};
			return;
		}
		int m = (b + e) >> 1;
		build(2 * node, b, m);
		build(2 * node + 1, m + 1, e);
		t[node] = merge(t[2 * node], t[2 * node + 1]);
	}
	pair<int, int> query(int node, int b, int e, int l, int r) {
		if (b > r or e < l)return {inf, 0};
		if (b >= l and e <= r)return t[node];
		int m = (b + e) >> 1;
		return merge(query(2 * node, b, m, l, r), query(2 * node + 1, m + 1, e, l, r));
	}
} s2;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	s1.build(1, 1, n);
	s2.build(1, 1, n);
	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		int g = s1.query(1, 1, n, l, r);
		auto mn = s2.query(1, 1, n, l, r);
		int ans = 0;
		if (mn.first == g) {
			ans = mn.second;
		}
		cout << (r - l + 1) - ans << '\n';
	}
	return 0;
}
