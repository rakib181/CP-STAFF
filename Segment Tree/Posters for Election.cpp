#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
int lazy[4 * N];
set<int> se;

void push(int node, int b, int e) {
	if (lazy[node] == -1)return;
	if (b != e) {
		lazy[2 * node] = lazy[node];
		lazy[2 * node + 1] = lazy[node];
	}
	lazy[node] = -1;
}

void upd(int node, int b, int e, int l, int r, int v) {
	if (b > r or e < l)return;
	if (b >= l and e <= r) {
		lazy[node] = v;
		return;
	}
	int m = (b + e) >> 1;
	push(node, b, e);
	upd(2 * node, b, m, l, r, v);
	upd(2 * node + 1, m + 1, e, l, r, v);
	if (lazy[2 * node] == lazy[2 * node + 1]) {
		lazy[node] = lazy[2 * node];
	}
}

void query(int node, int b, int e) {
	if (lazy[node] != -1) {
		se.insert(lazy[node]);
		return;
	}
	if (b == e) {
		return;
	}
	int m = (b + e) >> 1;
	query(2 * node, b, m);
	query(2 * node + 1, m + 1, e);
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
		cout << "Case " << cs++ << ": ";
		int n, id = 1;
		cin >> n; se.clear();
		memset(lazy, -1, sizeof lazy);
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			upd(1, 1, 2 * n, a, b, id++);
		}
		query(1, 1, 2 * n);
		cout << (int) se.size() << '\n';
	}
	return 0;
}
