#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e4 + 9, inf = 1e9 + 7;
int a[N];
struct node {
	int max_sub_sum, max_prefix, max_suffix, max_tot_sum;
};
node t[4 * N];

node merge(node x, node y) {
	if (x.max_sub_sum == inf)return y;
	if (y.max_sub_sum == inf)return x;
	node ans;
	ans.max_sub_sum = max(x.max_sub_sum, y.max_sub_sum);
	ans.max_sub_sum = max(ans.max_sub_sum, x.max_suffix + y.max_prefix);
	ans.max_prefix = max(x.max_prefix, x.max_tot_sum + y.max_prefix);
	ans.max_suffix = max(y.max_suffix, y.max_tot_sum + x.max_suffix);
	ans.max_tot_sum = x.max_tot_sum + y.max_tot_sum;
	return ans;
}

void build(int n, int b, int e) {
	if (b == e) {
		t[n] = {a[b], a[b], a[b], a[b]};
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
		t[n] = {v, v, v, v};
		return;
	}
	int m = (b + e) >> 1;
	upd(2 * n, b, m, i, v);
	upd(2 * n + 1, m + 1, e, i, v);
	t[n] = merge(t[2 * n], t[2 * n + 1]);
}

node query(int n, int b, int e, int l, int r) {
	if (b > r or e < l)return {inf, inf, inf, inf};
	if (b >= l and e <= r)return t[n];
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
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	build(1, 1, n);
	int q;
	cin >> q;
	while (q--) {
		int type;
		cin >> type;
		if (type == 1) {
			int l, r;
			cin >> l >> r;
			auto ans = query(1, 1, n, l, r);
			cout << ans.max_sub_sum << '\n';
		} else {
			int i, v;
			cin >> i >> v;
			upd(1, 1, n, i, v);
		}
	}
	return 0;
}
