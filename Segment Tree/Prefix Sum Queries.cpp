#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9, inf = 1e9 + 9;
int a[N];
struct node {
	ll max_prefix, sum;
};
node t[4 * N];

node merge(node x, node y) {
	if (x.max_prefix == inf)return y;
	if (y.max_prefix == inf)return x;
	node ans;
	ans.max_prefix = max({0LL, x.max_prefix, x.sum + y.max_prefix, x.sum + y.sum});
	ans.sum = x.sum + y.sum;
	return ans;
}

void build(int n, int b, int e) {
	if (b == e) {
		t[n] = {a[b], a[b]};
		return;
	}
	int m = (b + e) >> 1;
	build(2 * n, b, m);
	build(2 * n + 1, m + 1, e);
	t[n] = merge(t[2 * n], t[2 * n + 1]);
}

void upd(int n, int b, int e, int i, int v) {
	if (b > i or e < i)return;
	if (b == e) {
		t[n] = {v, v};
		return;
	}
	int m = (b + e) >> 1;
	upd(2 * n, b, m, i, v);
	upd(2 * n + 1, m + 1, e, i, v);
	t[n] = merge(t[2 * n], t[2 * n + 1]);
}

node query(int n, int b, int e, int l, int r) {
	if (b > r or e < l)return {inf, inf};
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
			upd(1, 1, n, i, v);
		} else {
			int l, r;
			cin >> l >> r;
			node ans = query(1, 1, n, l, r);
			cout << max(0LL, ans.max_prefix) << '\n';
		}
	}
	return 0;
}
