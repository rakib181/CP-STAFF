#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9, inf = 1e9 + 9;
int a[N];

struct min_ele {
	int t[4 * N];
	void build(int node, int b, int e) {
		if (b == e) {
			t[node] = a[b];
			return;
		}
		int m = (b + e) >> 1;
		build(2 * node, b, m);
		build(2 * node + 1, m + 1, e);
		t[node] = min(t[2 * node], t[2 * node + 1]);
	}
	int query(int node, int b, int e, int l, int r) {
		if (b > r or e < l)return inf;
		if (b >= l and e <= r)return t[node];
		int m = (b + e) >> 1;
		return min(query(2 * node, b, m, l, r), query(2 * node + 1, m + 1, e, l, r));
	}
} mn;

struct max_ele {
	int t[4 * N];
	void build(int node, int b, int e) {
		if (b == e) {
			t[node] = a[b];
			return;
		}
		int m = (b + e) >> 1;
		build(2 * node, b, m);
		build(2 * node + 1, m + 1, e);
		t[node] = max(t[2 * node], t[2 * node + 1]);
	}
	int query(int node, int b, int e, int l, int r) {
		if (b > r or e < l)return -inf;
		if (b >= l and e <= r)return t[node];
		int m = (b + e) >> 1;
		return max(query(2 * node, b, m, l, r), query(2 * node + 1, m + 1, e, l, r));
	}
} mx;

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
		int n, d;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		mn.build(1, 1, n);
		mx.build(1, 1, n);
		int ans = -inf;
		for (int i = 1; i + d - 1 <= n; i++) {
			int minn = mn.query(1, 1, n, i, i + d - 1);
			int maxx = mx.query(1, 1, n, i, i + d - 1);
			ans = max(ans, maxx - minn);
		}
		cout << ans << '\n';
	}
	return 0;
}
