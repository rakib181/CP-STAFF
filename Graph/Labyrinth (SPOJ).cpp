#include<bits/stdc++.h>
using namespace std;

int n, m;
const int N = 1005;
vector<vector<char>> grid(N, vector<char> (N));

int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

bool valid(int i, int j){
    return i >= 0 and j >= 0 and i < m and j < n and grid[i][j] != '#';
}
int ans, cnt, _x, _y;
void dfs(int i, int j){
    if(!valid(i, j))return;
    grid[i][j] = '#';
    cnt++;
    if(cnt > ans){
         _x = i, _y = j;
        ans = cnt;
    }
    for(int k = 0; k < 4; k++){
        int x = i + dx[k], y = j + dy[k];
        dfs(x, y);
    }
    grid[i][j] = '.';
    cnt--;
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
        cin >> n >> m; int x, y;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cin >> grid[i][j];
                if(grid[i][j] == '.') x = i, y = j;
            }
        }
        ans = 0, cnt = 0;
        dfs(x, y);
        dfs(_x, _y);
        cout << "Maximum rope length is " << ans - 1 << "." << '\n';
      }
      cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
      return 0;
}
