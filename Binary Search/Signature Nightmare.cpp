#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9, MX = 1e9 + 7;
int n, k, a[N], b[N];

bool possible(int x) {
	ll have = k;
	for (int i = 1; i <= n; i++) {
		ll need = 1LL * x * a[i] - b[i];
		if (need > have) return false;
		if (need > 0) have -= need;
	}
	return true;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int tt;
	cin >> tt;
	while (tt--) {
		cin >> n >> k;
		for (int i = 1; i <= n; i++)cin >> a[i];
		for (int i = 1; i <= n; i++)cin >> b[i];
		int l = 0, r = MX, ans = 1;
		while (l <= r) {
			int m = (l + r) >> 1;
			if (possible(m)) {
				ans = m;
				l = m + 1;
			} else r = m - 1;
		}
		cout << ans << '\n';
	}
	return 0;
}
