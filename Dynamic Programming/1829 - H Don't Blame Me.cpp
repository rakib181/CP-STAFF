#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9, MOD = 1e9 + 7;
int n, k;
int a[N], dp[N][64];


int knapsack(int i, int val) {
	if (i == n + 1)return __builtin_popcount(val) == k;
	if (dp[i][val] != -1)return dp[i][val];
	int res = knapsack(i + 1, val) + knapsack(i + 1, (a[i] & val)) % MOD;
	return dp[i][val] = res % MOD;
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
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		memset(dp, -1, (sizeof dp[0] * (n + 1)));
		cout << knapsack(1, 63) - (k == 6) << '\n';
	}
	return 0;
}
