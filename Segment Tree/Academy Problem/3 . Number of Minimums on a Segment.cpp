#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9, inf = 1e9 + 7;

struct node {
	int mn, cnt;
};
int a[N]; node t[4 * N];

node merge(node x, node y) {
	node ans;
	ans.mn = min(x.mn, y.mn);
	if (x.mn < y.mn) {
		ans.cnt = x.cnt;
	} else if (x.mn > y.mn) {
		ans.cnt = y.cnt;
	} else {
		ans.cnt = (x.cnt + y.cnt);
	}
	return ans;
}

void build(int n, int b, int e) {
	if (b == e) {
		t[n] = {a[b], 1};
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
		t[n] = {v, 1};
		return;
	}
	int m = (b + e) >> 1;
	upd(2 * n, b, m, i, v);
	upd(2 * n + 1, m + 1, e, i, v);
	t[n] = merge(t[2 * n], t[2 * n + 1]);
}
node query(int n, int b, int e, int l, int r) {
	if (b > r or e < l)return {inf, 1};
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
			i += 1;
			upd(1, 1, n, i, v);
		} else {
			int l, r;
			cin >> l >> r;
			l += 1;
			auto ans = query(1, 1, n, l, r);
			cout << ans.mn << ' ' << ans.cnt  << '\n';
		}
	}
	return 0;
}
