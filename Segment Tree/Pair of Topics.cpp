#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 4e5 + 9;
int a[N], b[N], t[4 * N];

void upd(int n, int b, int e, int i, int val) {
	if (b > i or e < i)return;
	if (b == e) {
		t[n] += val;
		return;
	}
	int m = (b + e) >> 1;
	upd(2 * n, b, m, i, val);
	upd(2 * n + 1, m + 1, e, i, val);
	t[n] = t[2 * n] + t[2 * n + 1];
}

int query(int n, int b, int e, int l, int r) {
	if (b > r or e < l)return 0;
	if (b >= l and e <= r)return t[n];
	int m = (b + e) >> 1;
	return query(2 * n, b, m, l, r) + query(2 * n + 1, m + 1, e, l, r);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n; set<int> se;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}
	for (int i = 1; i <= n; i++) {
		se.insert(a[i] - b[i]);
		se.insert(b[i] - a[i]);
	}
	map<int, int> mp; int id = 0;
	for (auto x : se) {
		mp[x] = ++id;
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += query(1, 1, id, mp[b[i] - a[i]] + 1, id);
		upd(1, 1, id, mp[a[i] - b[i]], 1);
	}
	cout << ans << '\n';
	return 0;
}
