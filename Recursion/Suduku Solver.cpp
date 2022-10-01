#include<bits/stdc++.h>
using namespace std;

bool isPossible(int i, int j, vector<vector<int>> &grid, int num, int n){
    for(int k = 0; k < n; k++){
        if(grid[i][k] == num or grid[k][j] == num)return false;
    }
    int sx = (i / 3) * 3, sy = (j / 3) * 3;
    for(int x = sx; x < sx + 3; x++){
        for(int y = sy; y < sy + 3; y++){
            if(grid[x][y] == num)return false;
        }
    }
    return true;
}

bool sudukuSolver(int i, int j, vector<vector<int>> &grid, int n){
    if(i == n){
        return true;
    }
    if(j == n){
        return sudukuSolver(i + 1, 0, grid, n);
    }
    if(grid[i][j] != 0){
        return sudukuSolver(i, j + 1, grid, n);
    }

    for(int num = 1; num <= 9; num++){
        if(isPossible(i, j, grid, num, n)){
            grid[i][j] = num;
            bool sub = sudukuSolver(i, j, grid, n);
            if(sub)return true;
        }
    }
    grid[i][j] = 0;
    return false;
}

int32_t main(){
     ios_base::sync_with_stdio(0);
      cin.tie(0); 
      #ifndef ONLINE_JUDGE 
      freopen("input.txt","r",stdin); 
      freopen("output.txt","w",stdout); 
      #endif
      auto start=clock();
      int n = 9;
      vector<vector<int>> ar(n + 1, vector<int> (n + 1));
      for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> ar[i][j];
        }
      }
      if(!sudukuSolver(0, 0, ar, n)){
        cout << "Solution doesn't exists" << '\n';
      }else{
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << ar[i][j] << ' ';
            }
            cout << '\n';
        }
      }
      cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
      return 0;
}
