#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 9, NO_OP = 1e7 + 9;
const ll inf = 1e18 + 9;
int a[N];
ll t[4 * N], lazy[4 * N];

ll merge(ll x, ll y) {
	return min(x, y);
}
void push(int node, int b, int e) {
	if (lazy[node] == 0)return;
	t[node] += lazy[node];
	if (b != e) {
		lazy[2 * node] += lazy[node];
		lazy[2 * node + 1] += lazy[node];
	}
	lazy[node] = 0;
}
void build(int node, int b, int e) {
	lazy[node] = 0;
	if (b == e) {
		t[node] = a[b];
		return;
	}
	int m = (b + e) >> 1;
	build(2 * node, b, m);
	build(2 * node + 1, m + 1, e);
	t[node] = merge(t[2 * node], t[2 * node + 1]);
}

void upd(int node, int b, int e, int l, int r, int v) {
	push(node, b, e);
	if (b > r or e < l)return;
	if (b >= l and e <= r) {
		lazy[node] = v;
		push(node, b, e);
		return;
	}
	int m = (b + e) >> 1;
	upd(2 * node, b, m, l, r, v);
	upd(2 * node + 1, m + 1, e, l, r, v);
	t[node] = merge(t[2 * node], t[2 * node + 1]);
}

ll query(int node, int b, int e, int l, int r) {
	push(node, b, e);
	if (b > r or e < l)return inf;
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
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	build(1, 0, n - 1);
	int q;
	cin >> q;
	cin.ignore();
	while (q--) {
		string s;
		getline(cin, s);
		int l, r, v;
		stringstream ss(s);
		ss >> l;
		ss >> r;
		string word;
		if (ss >> v) {
			if (l <= r) {
				upd(1, 0, n - 1, l, r, v);
			} else {
				upd(1, 0, n - 1, l, n - 1, v);
				upd(1, 0, n - 1, 0, r, v);
			}
		} else {
			if (l <= r) {
				cout << query(1, 0, n - 1, l, r) << '\n';
			} else {
				cout << min(query(1, 0, n - 1, l, n - 1), query(1, 0, n - 1, 0, r)) << '\n';
			}
		}

	}
	return 0;
}
