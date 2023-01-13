#include<bits/stdc++.h>
using namespace std;
const int N = 105; int n;
vector<vector<char>> grid(N, vector<char> (N));
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
bool valid(int x, int y){
   return x >= 0 and x < n and y >= 0 and y < n and grid[x][y] != '.';
}

void DFS(int x, int y){
    grid[x][y] = '.';
    for(int i = 0; i < 4; i++){
        int xx = x + dx[i], yy = y + dy[i];
        if(valid(xx, yy)){
            DFS(xx, yy);
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt, cs = 1;
    cin >> tt;
    while (tt--) {
       cin >> n;
       for(int i = 0; i < n; i++){
           for(int j = 0; j < n; j++){
               cin >> grid[i][j];
           }
       }
       int tot = 0;
       for(int i = 0; i < n; i++){
           for(int j = 0; j < n; j++){
               if(grid[i][j] == 'x'){
                   DFS(i, j);
                   tot++;
               }
           }
       }
       cout << "Case " << cs++ << ": " << tot << '\n';
    }
    return 0;
}
