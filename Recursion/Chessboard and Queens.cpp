#include<bits/stdc++.h>
using namespace std;
int n = 8, cnt = 0;

bool canPlace(vector<vector<char>> &grid, int x, int y){
   for(int i = 0; i < x; i++){
      if(grid[i][y] == '#')return false;
   }
   int r = x, c = y;
   while(r >= 0 and y >= 0){
       if(grid[r][c] == '#')return false;
       r--, c--;
   }
   while(x >= 0 and y < n){
      if(grid[x][y] == '#')return false;
      x--, y++;
   }
   return true;
}

void printGrid(vector<vector<char>> &grid){
     for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
         cout << grid[i][j] << ' ';
      }
      cout << '\n';
     }
}

bool NQUEEN(int i, vector<vector<char>> &grid){
   if(i == n){
      cnt++;
      //printGrid(grid);
      return false;
   }

   for(int j = 0; j < n; j++){
      if(canPlace(grid, i, j) and grid[i][j] != '*'){
           grid[i][j] = '#';
           bool success = NQUEEN(i + 1, grid);
           if(success)return true;
           grid[i][j] = '.';
      }
   }
   return false;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
     cin.tie(0);
     vector<vector<char>> grid(n + 1, vector<char> (n + 1));
     for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
         cin >> grid[i][j];
      }
     }
     NQUEEN(0, grid);
     cout << cnt << '\n';
     return 0;
}
