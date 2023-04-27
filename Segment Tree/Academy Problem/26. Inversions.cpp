#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
int a[N], t[4 * N];

void upd(int node, int b, int e, int i) {
	if (b > i or e < i)return;
	if (b == e) {
		t[node] += 1;
		return;
	}
	int m = (b + e) >> 1;
	upd(2 * node, b, m, i);
	upd(2 * node + 1, m + 1, e, i);
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
	for (int i = 1; i <= n; i++) {
		cout << query(1, 1, n, a[i] + 1, n) << ' ';
		upd(1, 1, n, a[i]);
	}
	return 0;
}
