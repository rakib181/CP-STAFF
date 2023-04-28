#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 9;
int d[N], a[N]; ll t[4 * N];

void build(int node, int b, int e) {
	if (b == e) {
		t[node] = a[b];
		return;
	}
	int m = (b + e) >> 1;
	build(2 * node, b, m);
	build(2 * node + 1, m + 1, e);
	t[node] = t[2 * node] + t[2 * node + 1];
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
	t[node] = t[2 * node] + t[2 * node + 1];
}

ll query(int node, int b, int e, int l, int r) {
	if (b > r or e < l)return 0;
	if (b >= l and e <= r)return t[node];
	int m = (b + e) >> 1;
	return query(2 * node, b, m, l, r) + query(2 * node + 1, m + 1, e, l, r);
}

void cal() {
	for (int i = 1; i < N; i++) {
		for (int j = i; j < N; j += i) {
			d[j] += 1;
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cal();
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	build(1, 1, n);
	set<int> alive;
	for (int i = 1; i <= n; i++) {
		if (a[i] > 2)alive.insert(i);
	}
	while (q--) {
		int type, l, r;
		cin >> type >> l >> r;
		if (type == 1) {
			vector<int> to_del;
			auto it = alive.lower_bound(l);
			while (it != alive.end() and (*it) <= r) {
				int i = *it;
				a[i] = d[a[i]];
				upd(1, 1, n, i, a[i]);
				if (a[i] <= 2) {
					to_del.push_back(i);
				}
				it++;
			}
			for (auto x : to_del) {
				alive.erase(x);
			}
		} else {
			cout << query(1, 1, n, l, r) << '\n';
		}
	}
	return 0;
}
