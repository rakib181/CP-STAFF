#include<bits/stdc++.h>
using namespace std;
int n, m;
int grid[11][11], dp[11][11];
int min_sum(int i, int j, int n, int m){
   if(i >= n || j >= m)return INT_MIN;
   if(i == n - 1 && j == m - 1)return grid[i][j];
   if(dp[i][j] != -1)return dp[i][j];
   return dp[i][j] = grid[i][j] + max(min_sum(i + 1, j, n, m), min_sum(i, j + 1, n, m));
}

int32_t main(){
     ios_base::sync_with_stdio(0);
      cin.tie(0); 
      #ifndef ONLINE_JUDGE 
      freopen("input.txt","r",stdin); 
      freopen("output.txt","w",stdout); 
      #endif
      auto start=clock();
      cin >> n >> m;
      for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
      }
      memset(dp, -1, sizeof dp);
      cout << min_sum(0, 0, n, m)<< '\n';
      cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
      return 0;
}
