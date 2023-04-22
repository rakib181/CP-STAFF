#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	string s;
	cin >> s;
	auto possible = [&] (int len) {
		for (int i = 0; i < n; i++) {
			int sz = 0, safe = -1;
			if (s[i] == 'o') {
				safe = i - 1;
				while (i < n and s[i] == 'o')sz += 1, i += 1;
			}
			if (i < n and sz >= len)return true;
			if (safe != -1 and safe >= 0 and sz >= len)return true;
		}
		return false;
	};
	int l = 1, r = n, ans = -1;
	while (l <= r) {
		int m = (l + r) >> 1;
		if (possible(m)) {
			ans = m;
			l = m + 1;
		} else r = m - 1;
	}
	cout << ans << '\n';
	return 0;
}
