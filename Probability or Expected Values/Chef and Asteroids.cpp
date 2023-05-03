#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9, MOD = 1e9 + 7;
int f[N];

void cal() {
	f[0] = 1;
	for (int i = 1; i < N; i++) {
		f[i] = 1LL * f[i - 1] * i % MOD;
	}
}

int bin(int x, int y) {
	int ans = 1;
	while (y) {
		if (y & 1)ans = 1LL * ans * x % MOD;
		x = 1LL * x * x % MOD;
		y >>= 1;
	}
	return ans;
}

int inv(int x) {
	return bin(x, MOD - 2);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cal();
	int n;
	cin >> n;
	map<int, int> cnt;
	for (int i = 1; i <= n; i++) {
		int x, y;
		cin >> x >> y;
		cnt[x] += 1;
	}
	int tot = f[n];
	int ans = 1;
	for (auto x : cnt) {
		ans = 1LL * ans * f[x.second] % MOD;
	}
	cout << 1LL * ans * inv(tot) % MOD << '\n';
	return 0;
}
