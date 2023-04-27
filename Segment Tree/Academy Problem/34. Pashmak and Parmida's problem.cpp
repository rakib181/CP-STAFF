#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 9;
int l[N], r[N], a[N], t[4 * N];

void upd(int node, int b, int e, int i, int v) {
	if (b > i or e < i)return;
	if (b == e) {
		t[node] += v;
		return;
	}
	int m = (b + e) >> 1;
	upd(2 * node, b, m, i, v);
	upd(2 * node + 1, m + 1, e, i, v);
	t[node] = t[2 * node] + t[2 * node + 1];
}

int query(int node, int b, int e, int l, int r) {
	if (b > r or e < l)return 0;
	if (b >= l and e <= r)return t[node];
	int m = (b + e) >> 1;
	return query(2 * node, b, m, l, r) + query(2 * node + 1, m + 1, e, l, r);
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
	map<int, int> f;
	for (int i = 1; i <= n; i++) {
		f[a[i]] += 1;
		l[i] = f[a[i]];
	}
	f.clear();
	for (int i = n; i >= 1; i--) {
		f[a[i]] += 1;
		r[i] = f[a[i]];
	}
	ll ans = 0;
	for (int i = n; i >= 1; i--) {
		ans += query(1, 1, n, 1, l[i] - 1);
		upd(1, 1, n, r[i], 1);
	}
	cout << ans << '\n';
	return 0;
}
