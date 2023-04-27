#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 9;
int a[N], pos[N], ans[N], t[4 * N];

int merge(int x, int y) {
	return x + y;
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
	t[node] = merge(t[2 * node], t[2 * node + 1]);
}

int query(int node, int b, int e, int l, int r) {
	if (b > r or e < l)return 0;
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
	int n;
	cin >> n;
	for (int i = 1; i <= 2 * n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= 2 * n; i++) {
		if (!pos[a[i]]) {
			pos[a[i]] = i;
		} else {
			upd(1, 1, 2 * n, pos[a[i]], 1);
			ans[a[i]] = query(1, 1, 2 * n, pos[a[i]], i);
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << ans[i] - 1 << ' ';
	}
	return 0;
}
