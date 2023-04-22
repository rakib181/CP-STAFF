#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;

struct YO {
	int first_ele, first_ele_occ, last_ele, last_ele_occ, strongest_community;
};
int a[N];
YO t[4 * N];

YO merge(YO x, YO y) {
	if (x.first_ele == -1)return y;
	if (y.first_ele == -1)return x;
	YO ans;
	ans.first_ele = x.first_ele;
	ans.first_ele_occ = x.first_ele_occ;
	if (x.first_ele == y.first_ele) {
		ans.first_ele_occ += y.first_ele_occ;
	}
	ans.last_ele = y.last_ele;
	ans.last_ele_occ = y.last_ele_occ;
	if (x.last_ele == y.last_ele)ans.last_ele_occ += x.last_ele_occ;
	ans.strongest_community = max(x.strongest_community, y.strongest_community);
	if (x.last_ele == y.first_ele) {
		ans.strongest_community = max(ans.strongest_community, x.last_ele_occ + y.first_ele_occ);
	}
	return ans;
}

void build(int node, int b, int e) {
	if (b == e) {
		t[node] = {a[b], 1, a[b], 1, 1};
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
		t[node] = {v, 1, v, 1, 1};
		return;
	}
	int m = (b + e) >> 1;
	upd(2 * node, b, m, i, v);
	upd(2 * node + 1, m + 1, e, i, v);
	t[node] = merge(t[2 * node], t[2 * node + 1]);
}

YO query(int node, int b, int e, int l, int r) {
	if (b > r or e < l)return { -1, -1, -1, -1, -1};
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
		int n, c, q;
		cin >> n >> c >> q;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		build(1, 1, n);
		while (q--) {
			int l, r;
			cin >> l >> r;
			auto ans = query(1, 1, n, l, r);
			cout << ans.strongest_community << '\n';
		}
	}
	return 0;
}
