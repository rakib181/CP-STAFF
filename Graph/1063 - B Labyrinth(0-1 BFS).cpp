#include<bits/stdc++.h>
using namespace std;
int n, m, sx, sy, L, R;

bool valid(int x, int y, vector<vector<char>> &grid, vector<vector<pair<int, int>>> &dist){
    return x >= 1 and x <= n and y >= 1 and y <= m and grid[x][y] != '*' and dist[x][y] == make_pair(-1,  -1);
}

int zero_oneBFS(vector<vector<char>> &grid){
    deque<pair<pair<int, int>, pair<int, int>>> dq;
    vector<vector<pair<int, int>>> dist(n + 1, vector<pair<int, int>> (m + 1, {-1, -1}));
    dq.push_back({{sx, sy}, {0, 0}});
    dist[sx][sy] = {0, 0};

    while (!dq.empty()){
        auto it = dq.front();
        dq.pop_front();
        pair<int, int> co = it.first;
        pair<int, int> wt = it.second;
        if(valid(co.first + 1, co.second, grid, dist)){
            dq.push_front({{co.first + 1, co.second}, wt});
            dist[co.first + 1][co.second] = wt;
        }
        if(valid(co.first - 1, co.second, grid, dist)){
            dq.push_front({{co.first - 1, co.second}, wt});
            dist[co.first - 1][co.second] = wt;
        }
        if(valid(co.first, co.second + 1, grid, dist)){
            dq.push_back({{co.first, co.second + 1}, {wt.first, wt.second + 1}});
            dist[co.first][co.second + 1] = make_pair(wt.first, wt.second + 1);
        }
        if(valid(co.first, co.second - 1, grid, dist)){
            dq.push_back({{co.first, co.second - 1}, {wt.first + 1, wt.second}});
            dist[co.first][co.second - 1] = make_pair(wt.first + 1, wt.second);
        }
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(dist[i][j] == make_pair(-1, -1))continue;
           if(dist[i][j].first <= L and dist[i][j].second <= R)cnt++;
        }
    }
  return cnt;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> sx >> sy >> L >> R;
    vector<vector<char>> grid(n + 1, vector<char> (m + 1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> grid[i][j];
        }
    }
    cout << zero_oneBFS(grid) << '\n';
    return 0;
}
