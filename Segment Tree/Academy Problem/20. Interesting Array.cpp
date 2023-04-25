#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 9, B = 30;
int a[N], l[N], r[N], required[N], ans[N], t[4 * N];

void build(int node, int b, int e) {
	if (b == e) {
		t[node] = ans[b];
		return;
	}
	int m = (b + e) >> 1;
	build(2 * node, b, m);
	build(2 * node + 1, m + 1, e);
	t[node] = t[2 * node] & t[2 * node + 1];
}

int query(int node, int b, int e, int l, int r) {
	if (b > r or e < l)return -1;
	if (b >= l and e <= r) {
		return t[node];
	}
	int m = (b + e) >> 1;
	return query(2 * node, b, m, l, r) & query(2 * node + 1, m + 1, e, l, r);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, constraints;
	cin >> n >> constraints;
	for (int i = 1; i <= constraints; i++) {
		cin >> l[i] >> r[i] >> required[i];
	}
	for (int k = 0; k < B; k++) {
		for (int i = 1; i <= n; i++) {
			a[i] = 0;
		}
		for (int i = 1; i <= constraints; i++) {
			if ((required[i] >> k) & 1) {
				a[l[i]] += 1;
				a[r[i] + 1] -= 1;
			}
		}
		for (int i = 1; i <= n; i++) {
			a[i] += a[i - 1];
		}
		for (int i = 1; i <= n; i++) {
			if (a[i]) {
				ans[i] |= (1 << k);
			}
		}
	}
	build(1, 1, n);
	for (int i = 1; i <= constraints; i++) {
		if (query(1, 1, n, l[i], r[i]) != required[i]) {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
	return 0;
}
