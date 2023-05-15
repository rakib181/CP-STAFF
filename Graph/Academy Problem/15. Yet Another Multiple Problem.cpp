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
	int n, m, cs = 1;
	while (cin >> n >> m and n) {
		cout << "Case " << cs++ << ": ";
		vector<bool> bad(10, false);
		for (int i = 0; i < m; i++) {
			int d;
			cin >> d;
			bad[d] = true;
		}
		vector<bool> vis(n + 1, false);
		vector<int> digits(n + 1, 0), par(n + 1, 0);
		queue<int> q;
		for (int i = 1; i < 10; i++) {
			int d = i % n;
			if (!bad[i] and !vis[d]) {
				q.push(d);
				vis[d] = true;
				digits[d] = i;
				par[d] = -1;
			}
		}
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			for (int i = 0; i < 10; i++) {
				int nxt_num = x * 10 + i;
				nxt_num %= n;
				if (!bad[i] and !vis[nxt_num]) {
					q.push(nxt_num);
					digits[nxt_num] = i;
					par[nxt_num] = x;
					vis[nxt_num] = true;
				}
			}
		}
		if (vis[0]) {
			int x = 0;
			vector<int> path;
			while (x != -1) {
				path.emplace_back(digits[x]);
				x = par[x];
			}
			reverse(path.begin(), path.end());
			for (auto xx : path) {
				cout << xx;
			}
			cout << '\n';
		}
		else cout << "-1\n";
	}
	return 0;
}
