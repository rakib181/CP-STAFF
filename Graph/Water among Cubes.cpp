#include<bits/stdc++.h>
using namespace std;
#define int long long int
int n, m, tot;
const int N = 105;
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
vector<vector<bool>> vis(N, vector<bool> (N));
vector<vector<int>> grid(N, vector<int> (N));
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

void init(){
    for(int i = 1; i < N; i++){
        for(int j = 1; j < N; j++){
            grid[i][j] = 0;
            vis[i][j] = false;
        }
    }
}

bool valid(int x, int y, int val){
    return x >= 1 and x <= n and y >= 1 and y <= m and !vis[x][y] and grid[x][y] <= val;
}

void DFS(int x, int y, int val){
    vis[x][y] = true;
    for(int i = 0; i < 4; i++){
        int xx = x + dx[i], yy = y + dy[i];
        if(valid(xx, yy, val)){
            tot += (val - grid[xx][yy]);
            DFS(xx, yy, val);
        }else if(grid[xx][yy] > val){
            pq.push({grid[xx][yy], {xx, yy}});
        }
    }
}



int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        cin >> n >> m;
        init();
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cin >> grid[i][j];
                if(i == 1 or j == 1 or i == n or j == m)pq.push({grid[i][j], {i, j}});
            }
        }
        int ans = 0;
        while (!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int i = it.second.first, j = it.second.second, val = it.first; tot = 0;
            if(!vis[i][j]){
                DFS(i, j, val);
            }
            ans += tot;
        }
        cout << ans << '\n';
    }
    return 0;
}
