#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 9;
int n, q, a[N], t[4 * N];

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

void upd(int node, int b, int e, int i, int v) {
	if (b > i or e < i)return;
	if (b == e) {
		t[node] = v;
		return;
	}
	int m = (b + e) >> 1;
	upd(2 * node, b, m, i, v);
	upd(2 * node + 1, m + 1, e, i, v);
	t[node] = max(t[2 * node], t[2 * node + 1]);
}

int query(int node, int b, int e, int l, int r) {
	if (b > r or e < l)return 0;
	if (b >= l and e <= r)return t[node];
	int m = (b + e) >> 1;
	return max(query(2 * node, b, m, l, r), query(2 * node + 1, m + 1, e, l, r));
}

int Q(int x, int low) {
	int l = low, r = n, idx = -1;
	while (l <= r) {
		int m = (l + r) >> 1;
		int val = query(1, 1, n, low, m);
		if (val >= x) {
			idx = m;
			r = m - 1;
		} else l = m + 1;
	}
	return idx != -1 ? idx - 1 : -1;
}


signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
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
			int x, l;
			cin >> x >> l;
			l += 1;
			cout << Q(x, l) << '\n';
		}
	}
	return 0;
}
