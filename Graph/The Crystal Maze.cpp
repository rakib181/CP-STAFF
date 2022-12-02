#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int N = 1005;
int n, m, q, ans;
vector<vector<char>> g(N, vector<char> (N));
vector<vector<int>> dp(N, vector<int> (N));
vector<vector<bool>> vis(N, vector<bool> (N));
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

void DFS(int x, int y, vector<pair<int, int>> &co){
    vis[x][y] = true;
    co.emplace_back(x, y);
    if(g[x][y] == 'C')ans++;
    for(int i = 0; i < 4; i++) {
        int xx = x + dx[i], yy = y + dy[i];
        if (xx < 1 or xx > n or yy < 1 or yy > m or g[xx][yy] == '#' or vis[xx][yy])continue;
        DFS(xx, yy, co);
    }
}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt, cs = 1;
    cin >> tt;
    while (tt--) {
        cout << "Case " << cs++ << ":\n";
        cin >> n >> m >> q;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cin >> g[i][j];
                dp[i][j] = -1;
                vis[i][j] = false;
            }
        }
        while (q--){
            int x, y;
            cin >> x >> y;
            if(dp[x][y] == -1){
                ans = 0;
                vector<pair<int, int>> co;
                DFS(x, y, co);
                for(auto xx : co){
                    dp[xx.first][xx.second] = ans;
                }
                cout << dp[x][y] << '\n';
            }else{
               cout << dp[x][y] << '\n';
            }
        }

    }
    return 0;
}
