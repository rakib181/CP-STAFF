#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
int n, c, a[N], prefix[N];

bool feasible(int m) {
	for (int i = 1; i + m - 1 <= n; i++) {
		if (prefix[i + m - 1] - prefix[i - 1] <= c)return true;
	}
	return false;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> n >> c;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		prefix[i] = prefix[i - 1] + a[i];
	}
	int l = 1, r = n, ans = 0;
	while (l <= r) {
		int m = (l + r) >> 1;
		if (feasible(m)) {
			ans = m;
			l = m + 1;
		} else r = m - 1;
	}
	cout << ans << '\n';
	return 0;
}
