#include<bits/stdc++.h>
using namespace std;
int n, m, idx;
const int N = 55;
vector<vector<char>> grid(N, vector<char> (N));
int dx[4] = {0, -1, 1, 0}, dy[4] = {-1, 0, 0, 1};
int ans[N * N];

bool valid(int x, int y){
    return x >= 1 and x <= n and y >= 1 and y <= m and grid[x][y] != '.';
}

void COUNT(int x, int y){
    if(grid[x][y] == 'X') {
        grid[x][y] = '.';
        for (int i = 0; i < 4; i++) {
           if(valid(x + dx[i], y + dy[i])) COUNT(x + dx[i], y + dy[i]);
        }
    }
}

void DFS(int x, int y){
    if(grid[x][y] != '.'){
        if(grid[x][y] == 'X'){
            COUNT(x, y);
            ans[idx]++;
        }else{
            grid[x][y] = '.';
        }
        for(int i = 0; i < 4; i++){
           if(valid(x + dx[i], y + dy[i])) DFS(x + dx[i], y + dy[i]);
        }
    }
}

int32_t main(){
    int cs = 1;
    while (cin >> m >> n, n and m){
        idx = 0;
        memset(ans, 0, sizeof ans);
        for(int i = 1; i <= n; i++){
           grid[i].clear();
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cin >> grid[i][j];
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(grid[i][j] != '.'){
                    DFS(i, j);
                    idx++;
                }
            }
        }
        cout << "Throw " << cs++ << '\n';
        sort(ans, ans + idx);
        cout << ans[0];
        for(int i = 1; i < idx; i++){
            cout << " " << ans[i];
        }
        cout << "\n\n";
    }
    return 0;
}
