#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 998244353;

int mul_mod(int x, int y) {
	int ans = 0;
	while (y) {
		if (y & 1)ans = (1LL * ans + x) % MOD;
		x = (1LL * x + x) % MOD;
		y >>= 1;
	}
	return ans;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, k;
	cin >> n >> k;
	int a[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int t_n = n, c = 0; ll tot = 0;
	while (true) {
		tot += t_n;
		t_n -= 1;
		c += 1;
		if (c >= k)break;
	}
	int other = n - k + 1;
	int ans = 1;
	vector<int> pos;
	for (int i = 1; i <= n; i++) {
		if (a[i] >= other)pos.emplace_back(i);
	}
	for (int i = 0; i + 1 < (int) pos.size(); i++) {
		ans = mul_mod(ans, pos[i + 1] - pos[i]);
	}
	cout << tot << ' ' << ans << '\n';
	return 0;
}
