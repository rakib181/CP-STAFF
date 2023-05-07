#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int bin(int x, int y) {
	int ans = 1;
	while (y) {
		if (y & 1) ans = ans * x;
		x *= x;
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
	string s1, s2;
	cin >> s1 >> s2;
	int need = 0;
	for (auto x : s1) {
		if (x == '+') need += 1;
		else need -= 1;
	}
	int n = (int) s1.size();
	bool vis[n];
	for (int i = 0; i < n; i++) {
		vis[i] = false;
	}
	int tot = 0;
	for (int i = 0; i < n; i++) {
		if (s2[i] != '?')vis[i] = true;
		else tot += 1;
	}
	map<string, bool> mp;
	int c = 0;
	for (int i = 0; i < (1 << n); i++) {
		char t[n];
		for (int j = 0; j < n; j++) {
			if (!vis[j]) {
				if ((i >> j) & 1) {
					t[j] = '+';
				} else t[j] = '-';
			} else t[j] = s2[j];
		}
		string s;
		for (int j = 0; j < n; j++) {
			s += t[j];
		}
		mp[s] = true;
	}

	for (auto x : mp) {
		int cnt = 0;
		for (auto it : x.first) {
			if (it == '+')cnt += 1;
			else cnt -= 1;
		}
		if (cnt == need)c += 1;
	}
	tot = bin(2, tot);
	cout << fixed << setprecision(10) << c / (1.0 * tot) << '\n';
	return 0;
}
