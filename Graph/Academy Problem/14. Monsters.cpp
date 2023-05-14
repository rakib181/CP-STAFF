#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1005, inf = 1e9;
int n, m, dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
vector<vector<char>> g(N, vector<char> (N));
int can_go[N][N];
pair<int, int> par[N][N];

bool valid(int x, int y) {
	return x >= 1 and x <= n and y >= 1 and y <= m;
}

vector<vector<int>> bfs(vector<pair<int, int>> &a) {
	vector<vector<int>> d(N, vector<int> (N, inf));
	queue<pair<int, int>> q;
	for (auto x : a) {
		q.push(x);
		d[x.first][x.second] = 0;
	}
	while (!q.empty()) {
		auto it = q.front();
		q.pop();
		int x = it.first, y = it.second;
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i], yy = y + dy[i];
			if (valid(xx, yy) and g[xx][yy] != '#' and d[x][y] + 1 < d[xx][yy]) {
				d[xx][yy] = d[x][y] + 1;
				q.push(make_pair(xx, yy));
			}
		}
	}
	return d;
}


signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> n >> m;
	vector<pair<int, int>> a; pair<int, int> me;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> g[i][j];
			if (g[i][j] == 'A')me = make_pair(i, j);
			if (g[i][j] == 'M')a.emplace_back(i, j);
		}
	}
	vector<pair<int, int>> t;
	t.emplace_back(me);
	vector<vector<int>> d1 = bfs(t);
	t = a;
	vector<vector<int>> d2 = bfs(t);
	vector<vector<int>> d(n + 1, vector<int> (m + 1, inf));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			can_go[i][j] = (g[i][j] != '#') and (d1[i][j] < d2[i][j]);
		}
	}
	queue<pair<int, int>> q;
	q.push(me);
	d[me.first][me.second] = 0;
	while (!q.empty()) {
		auto it = q.front();
		q.pop();
		int x = it.first, y = it.second;
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i], yy = y + dy[i];
			if (valid(xx, yy) and can_go[xx][yy] and d[x][y] + 1 < d[xx][yy]) {
				d[xx][yy] = d[x][y] + 1;
				par[xx][yy] = make_pair(x, y);
				q.push(make_pair(xx, yy));
			}
		}
	}
	auto x = make_pair(-1, -1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if ((i == 1 or j == 1 or i == n or j == m) and d[i][j] != inf) {
				x = make_pair(i, j);
			}
		}
	}
	if (x.first == -1)cout << "NO\n";
	else {
		cout << "YES\n" << d[x.first][x.second] << '\n';
		auto t = x;
		vector<pair<int, int>> path;
		while (t != me) {
			path.emplace_back(t);
			t = par[t.first][t.second];
		}
		path.emplace_back(me);
		reverse(path.begin(), path.end());
		for (int i = 0; i + 1 < (int) path.size(); i++) {
			int di = path[i].first - path[i + 1].first;
			int dy = path[i].second - path[i + 1].second;
			if (di == -1)cout << 'D';
			else if (di == 1)cout << 'U';
			else if (dy == 1)cout << 'L';
			else cout << 'R';
		}
	}
	return 0;
}
