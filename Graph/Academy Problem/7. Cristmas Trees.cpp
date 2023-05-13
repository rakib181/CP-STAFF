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
	int n, m;
	cin >> n >> m;
	queue<int> q; map<int, int> d;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		q.push(x);
		d[x] = 0;
	}
	vector<int> nearest;
	ll ans = 0;
	while (!q.empty() and m) {
		int node = q.front();
		q.pop();
		if (d.find(node - 1) == d.end() and m) {
			d[node - 1] = d[node] + 1;
			ans += d[node - 1];
			q.push(node - 1); m -= 1;
			nearest.push_back(node - 1);
		}
		if (d.find(node + 1) == d.end() and m) {
			d[node + 1] = d[node] + 1;
			ans += d[node + 1];
			q.push(node + 1); m -= 1;
			nearest.push_back(node + 1);
		}
	}
	cout << ans << '\n';
	for (auto x : nearest) {
		cout << x << ' ';
	}
	return 0;
}
