#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
int t[4 * N];

void upd(int node, int b, int e, int i) {
	if (b > i or e < i)return;
	if (b == e) {
		t[node] += 1;
		return;
	}
	int m = (b + e) >> 1;
	upd(2 * node, b, m, i);
	upd(2 * node + 1, m + 1, e, i);
	t[node] = t[2 * node] + t[2 * node + 1];
}

int query(int node, int b, int e, int l, int r) {
	if (b > r or e < l)return 0;
	if (b >= l and e <= r)return t[node];
	int m = (b + e) >> 1;
	return query(2 * node, b, m, l, r) + query(2 * node + 1, m + 1, e, l, r);
}

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
	string r = s;
	reverse(r.begin(), r.end());
	int p[n]; map<int, vector<int>> mp_s, mp_r;
	for (int i = 0; i < n; i++) {
		mp_s[s[i] - 'a'].emplace_back(i);
	}
	for (int i = 0; i < n; i++) {
		mp_r[r[i] - 'a'].emplace_back(i);
	}
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < (int) mp_s[i].size(); j++) {
			p[mp_r[i][j]] = mp_s[i][j];
		}
	}
	ll ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		ans += query(1, 0, n - 1, 0, p[i] - 1);
		upd(1, 0, n - 1, p[i]);
	}
	cout << ans << '\n';
	return 0;
}
