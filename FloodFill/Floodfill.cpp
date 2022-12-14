#include<bits/stdc++.h>
using namespace std;

int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

void DFS(int x, int y, vector<vector<int>> &grid, int n, int m, int col, int newColor){
    grid[x][y] = newColor;
    for(int i = 0; i < 4; i++){
        int xx = x + dx[i], yy = y + dy[i];
        if(xx < 0 or xx >= n or yy < 0 or yy >= m or grid[xx][yy] != col)continue;
        DFS(xx, yy, grid, n, m, col, newColor);
    }
}

vector<vector<int>> floodFill(vector<vector<int>> image, int sr, int sc, int newColor){
     vector<vector<int>> grid = image;
     int n = (int) grid.size(), m = (int) grid[0].size();
     DFS(sr, sc, grid, n, m, grid[sr][sc], newColor);
     return grid;
}
int main(){
    vector<vector<int>> grid = {
       {1, 1, 1},
       {1, 1, 0}, 
       {1, 0, 1}
    };
    int sr = 1, sc = 1, newColor = 2;
    vector<vector<int>> ans = floodFill(grid, sr, sc, newColor);
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[0].size(); j++){
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}
