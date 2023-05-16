#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5005, NX = 505;
int digits[NX][N]; pair<int, int> par[NX][N];
bool vis[NX][N];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int d, s;
	cin >> d >> s;
	queue<pair<int, int>> q;
	for (int i = 0; i < 10; i++) {
		int x = i % d;
		vis[x][i] = true;
		digits[x][i] = i;
		q.push(make_pair(x, i));
		par[x][i] = make_pair(-1, -1);
	}
	while (!q.empty()) {
		auto it = q.front();
		q.pop();
		int m = it.first, ds = it.second;
		if (m == 0 and ds == s) {
			vector<int> path;
			pair<int, int> x = it;
			while (x.first != -1 and x.second != -1) {
				path.emplace_back(digits[x.first][x.second]);
				x = par[x.first][x.second];
			}
			reverse(path.begin(), path.end());
			for (auto x : path) {
				cout << x;
			}
			return 0;
		}
		if (ds > s)continue;
		for (int i = 0; i < 10; i++) {
			int _m = (m * 10 + i) % d;
			int _ds = ds + i;
			if (!vis[_m][_ds]) {
				vis[_m][_ds] = true;
				par[_m][_ds] = make_pair(m, ds);
				digits[_m][_ds] = i;
				q.push(make_pair(_m, _ds));
			}
		}
	}
	cout << "-1\n";
	return 0;
}
