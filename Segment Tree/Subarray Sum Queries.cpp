#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9, inf = 1e9 + 9;
int a[N];
struct node {
	ll max_sub_sum, max_prefix, max_suffix, sum;
};
node t[4 * N];

node merge(node x, node y) {
	if (x.max_sub_sum == inf)return y;
	if (y.max_sub_sum == inf)return x;
	node ans;
	ans.max_sub_sum = max(x.max_sub_sum, y.max_sub_sum);
	ans.max_sub_sum = max(ans.max_sub_sum, x.max_suffix + y.max_prefix);
	ans.max_prefix = max(x.max_prefix, x.sum + y.max_prefix);
	ans.max_suffix = max(y.max_suffix, y.sum + x.max_suffix);
	ans.sum = x.sum + y.sum;
	return ans;
}

void build(int n, int b, int e) {
	if (b == e) {
		if (a[b] > 0)t[n] = {a[b], a[b], a[b], a[b]};
		else t[n] = {0, 0, 0, a[b]};
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
		if (v > 0)t[n] = {v, v, v, v};
		else t[n] = {0, 0, 0, v};
		return;
	}
	int m = (b + e) >> 1;
	upd(2 * n, b, m, i, v);
	upd(2 * n + 1, m + 1, e, i, v);
	t[n] = merge(t[2 * n], t[2 * n + 1]);
}

node query(int n, int b, int e, int l, int r) {
	if (b > r or e < l)return {inf, inf, inf, inf};
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
		int i, v;
		cin >> i >> v;
		upd(1, 1, n, i, v);
		node ans = query(1, 1, n, 1, n);
		cout << ans.max_sub_sum << '\n';
	}
	return 0;
}
