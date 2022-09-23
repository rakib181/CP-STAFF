#include<bits/stdc++.h>
using namespace std;
int n, m;

bool valid(int i, int j, vector<vector<char>> &grid){
    return i >= 0 and i < n and j >= 0 and j < m and grid[i][j] == '.';
}

void dfs(int i, int j, vector<vector<char>> &grid){
     while(valid(i, j, grid)){
         i++;
     }
     grid[i - 1][j] = '*';
}

int32_t main(){
     ios_base::sync_with_stdio(0);
      cin.tie(0); 
      #ifndef ONLINE_JUDGE 
      freopen("input.txt","r",stdin); 
      freopen("output.txt","w",stdout); 
      #endif
      auto start=clock();
      int tt;
      cin >> tt;
      while(tt--){
        cin >> n >> m;
        vector<vector<char>> grid(n + 1, vector<char> (m + 1));
        for(int i = 0; i <  n; i++){
            for(int j = 0; j < m; j++){
                cin >> grid[i][j];
            }
        }
        for(int i = n - 1; i >= 0; i--){
            for(int j = m - 1; j >= 0; j--){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.'){
                    grid[i][j] = '.';
                    dfs(i + 1, j, grid);
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << grid[i][j];
            }
            cout << '\n';
        }
      }
      cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
      return 0;
}
