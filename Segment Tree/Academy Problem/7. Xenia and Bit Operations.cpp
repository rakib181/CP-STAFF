#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = (1 << 17) + 9;
int a[N], t[4 * N];

int merge(int x, int y, int b, int e) {
	int exp = __lg(e - b + 1);
	if (exp & 1)return x | y;
	else return x ^ y;
}

void build(int node, int b, int e) {
	if (b == e) {
		t[node] = a[b];
		return;
	}
	int m = (b + e) >> 1;
	build(2 * node, b, m);
	build(2 * node + 1, m + 1, e);
	t[node] = merge(t[2 * node], t[2 * node + 1], b,  e);
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
	t[node] = merge(t[2 * node], t[2 * node + 1], b, e);
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
	n = (1 << n);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	build(1, 1, n);
	while (q--) {
		int i, v;
		cin >> i >> v;
		upd(1, 1, n, i, v);
		cout << t[1] << '\n';
	}
	return 0;
}
