#include<bits/stdc++.h>
using namespace std;

int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

void DFS(int x, int y, vector<vector<char>> &grid, int n, int m){
    grid[x][y] = '0';
    for(int i = 0; i < 4; i++){
        int xx = x + dx[i], yy = y + dy[i];
        if(xx < 0 or xx >= n or yy < 0 or yy >= m or grid[xx][yy] == '0')continue;
        DFS(xx, yy, grid, n, m);
    }
}

int numIslands( vector<vector<char>> grid)
{
    int n = (int) grid.size(), m = (int) grid[0].size();
    int cc = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == '1'){
                cc++;
                DFS(i, j, grid, n, m);
            }
        }
    }
    return cc;
}
