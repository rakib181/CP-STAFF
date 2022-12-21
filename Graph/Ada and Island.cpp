#include<bits/stdc++.h>
using namespace std;
#define int long long int
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--){
       int n, m;
       cin >> n >> m;
       vector<vector<char>> grid(n + 1, vector<char> (m + 1));
       for(int i = 1; i <= n; i++){
           for(int j = 1; j <= m; j++){
               cin >> grid[i][j];
           }
       }
        int p = 0, q = n * m * 2, cnt;
       auto valid = [&](int x, int y){
           return x >= 1 and x <= n and y >= 1 and y <= m and grid[x][y] == '#';
       };
        function<void(int, int)> DFS = [&] (int x, int y){
           grid[x][y] = '~';
           cnt++;
           for(int i = 0; i < 4; i++){
               int xx = x + dx[i], yy = y + dy[i];
               if(valid(xx, yy)){
                   DFS(xx, yy);
               }
           }
       };
       for(int i = 1; i <= n; i++){
           for(int j = 1; j <= m; j++){
               if(grid[i][j] == '#'){
                   cnt = 0;
                   DFS(i, j);
                   p += (cnt * (cnt * 2));
               }
           }
       }
       int g = __gcd(p, q);
       p /= g, q /= g;
       if(q == 1){
           cout << p << '\n';
       }else{
           cout << p << " / " << q << '\n';
       }
    }
    return 0;
}
