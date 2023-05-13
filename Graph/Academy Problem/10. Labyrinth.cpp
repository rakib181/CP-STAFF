#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1005, inf = 1e9 + 7;
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
vector<vector<char>> g(N, vector<char> (N));
int n, m, d[N][N];
pair<int, int> par[N][N];

bool valid(int x, int y) {
	return x >= 1 and x <= n and y >= 1 and y <= m;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> n >> m; pair<int, int > st, en;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> g[i][j];
			if (g[i][j] == 'A')st = make_pair(i, j);
			if (g[i][j] == 'B')en = make_pair(i, j);
			d[i][j] = inf;
		}
	}
	queue<pair<int, int>> q;
	q.push(st);
	d[st.first][st.second] = 0;
	while (!q.empty()) {
		auto it = q.front();
		q.pop();
		int x = it.first, y = it.second;
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i], yy = y + dy[i];
			if (valid(xx, yy) and g[xx][yy] != '#' and d[x][y] + 1 < d[xx][yy]) {
				d[xx][yy] = d[x][y] + 1;
				par[xx][yy] = make_pair(x, y);
				q.push(make_pair(xx, yy));
			}
		}
	}
	if (d[en.first][en.second] == inf)cout << "NO\n";
	else {
		cout << "YES\n" << d[en.first][en.second] << '\n';
		pair<int, int> cur = en;
		vector<pair<int, int>> path;
		while (cur != st) {
			path.emplace_back(cur);
			cur = par[cur.first][cur.second];
		}
		path.emplace_back(st);
		reverse(path.begin(), path.end());
		for (int i = 0; i + 1 < (int) path.size(); i++) {
			int d1 = path[i].first - path[i + 1].first;
			int d2 = path[i].second - path[i + 1].second;
			if (d1 == 1)cout << 'U';
			else if (d1 == -1)cout << 'D';
			else if (d2 == 1)cout << 'L';
			else cout << 'R';
		}
	}
	return 0;
}
