#include<bits/stdc++.h>
using namespace std;
#define int long long int

int n, ans;
void DFS(int x, int y, vector<string> &grid){
    grid[x][y] = 'W';
    ans++;
    if(x == 0){
        if(grid[1][y] == 'B')DFS(1, y, grid);
        else if(y + 1 < n) DFS(x, y + 1, grid);
        else if(y - 1 >= 0 and grid[x][y - 1] == 'B')DFS(x, y - 1, grid);
    }else{
        if(grid[0][y] == 'B')DFS(0, y, grid);
        else if(y + 1 < n) DFS(x, y + 1, grid);
        else if(y - 1 >= 0 and grid[x][y - 1] == 'B')DFS(x, y - 1, grid);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--){
        cin >> n;
        vector<string> grid(2);
        for(int i = 0; i < 2; i++)cin >> grid[i];

        vector<pair<int, int>> a;
        for(int i = 0; i < n; i++){
            if(grid[0][i] == 'B'){
                a.emplace_back(0, i);
                if(grid[1][i] == 'B')a.emplace_back(1, i);
                break;
            }
            if(grid[1][i] == 'B') {
                a.emplace_back(1, i);
                if(grid[0][i] == 'B')a.emplace_back(0, i);
                break;
            }
        }
        int cnt = 0;
        for(int i = 0; i < 2; i++){
            for(auto  x : grid[i]){
                if(x == 'B')cnt++;
            }
        }
        bool ok = false;
        for(auto x : a){
            vector<string> vis = grid;
            if(grid[x.first][x.second] == 'B'){
                ans = 0;
                DFS(x.first, x.second, vis);
                if(cnt == ans){
                    ok = true;
                    break;
                }
            }
        }
        if(ok) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}
