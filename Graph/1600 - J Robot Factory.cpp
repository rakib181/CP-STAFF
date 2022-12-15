#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 1e3 + 9;
vector<vector<int>> grid(N, vector<int> (N));
vector<vector<bool>> vis(N, vector<bool> (N, false));
int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
int n, m, cnt = 0;

void DFS(int x, int y){
    vis[x][y] = true;
    cnt++;
    for(int i = 0; i < 4; i++){
        if(!(grid[x][y] & (1 << i))){
            int xx = x + dx[i], yy = y + dy[i];
            if(xx > 0 and xx <= n and yy > 0 and yy <= m and !vis[xx][yy]){
                DFS(xx, yy);
            }
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> grid[i][j];
        }
    }
    priority_queue<int> pq;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(!vis[i][j]){
                int cur = cnt;
                DFS(i, j);
                pq.push(cnt - cur);
            }
        }
    }
    while (!pq.empty()){
        cout << pq.top() << ' ';
        pq.pop();
    }
    return 0;
}
