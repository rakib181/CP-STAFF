#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9, MOD = 1e9 + 7;
int f[N];

void cal() {
	f[0] = f[1] = 1;
	for (int i = 2; i < N; i++) {
		f[i] = 1LL * f[i - 1] * i % MOD;
	}
}

int bin(int x, int y) {
	int ans = 1;
	while (y) {
		if (y & 1) ans = 1LL * ans * x % MOD;
		x = 1LL * x * x % MOD;
		y >>= 1;
	}
	return ans;
}

int inv(int x) {
	return bin(x, MOD - 2);
}

int nCr(int n, int r) {
	if (r > n)return 0;
	int den = 1LL * f[r] * f[n - r] % MOD;
	return 1LL * f[n] * inv(den) % MOD;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cal();
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a, a + n);
		int ans = 1;
		for (int i = 0; i < n; i++) {
			if (a[i] <= i + 1) {
				int rgt = bin(2, n - i - 1);
				int lft = nCr(i, a[i] - 1);
				ans = (1LL * ans + ((1LL * lft * rgt) % MOD)) % MOD;
			}
		}
		cout << ans - 1 << '\n';
	}
	return 0;
}
