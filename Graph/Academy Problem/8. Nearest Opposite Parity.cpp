#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9, inf = 1e9 + 7;
vector<int> g[N];
int n, a[N], ans[N], d[N];

void solve(vector<int> a, vector<int> b) {
	queue<int> q;
	for (auto x : a) {
		q.push(x);
		d[x] = 0;
	}
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (auto x : g[node]) {
			if (d[node] + 1 < d[x]) {
				d[x] = d[node] + 1;
				q.push(x);
			}
		}
	}
	for (auto x : b) {
		ans[x] = d[x];
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> n;
	vector<int> even, odd;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (i - a[i] >= 1)g[i - a[i]].push_back(i);
		if (i + a[i] <= n)g[i + a[i]].push_back(i);
		if (a[i] & 1)odd.push_back(i);
		else even.push_back(i);
	}
	for (int i = 1; i <= n; i++)d[i] = inf, ans[i] = -1;
	solve(even, odd);
	for (int i = 1; i <= n; i++) {
		d[i] = inf;
	}
	solve(odd, even);
	for (int i = 1; i <= n; i++) {
		if (ans[i] == inf)ans[i] = -1;
		cout << ans[i] << ' ';
	}
	return 0;
}
