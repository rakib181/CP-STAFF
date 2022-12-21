#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 9;
int dx[8] = {-2, -2, -1, 1, 2, 2, 1, -1}, dy[8] = {-1, 1, 2, 2, 1, -1, -2, -2};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--){
        string s, ss;
        cin >> s >> ss;
        int s_x = (s[0] - 'a') + 1, s_y = (s[1] - '0'), d_x = (ss[0] - 'a') + 1, d_y = (ss[1] - '0');
        vector<vector<int>> dist(N, vector<int> (N, INT_MAX));
        auto valid = [&](int x, int y){
            return x >= 1 and x <= 8 and y >= 1 and y <= 8;
        };
        queue<pair<int, int>> q;
        dist[s_x][s_y] = 0;
        q.push({s_x, s_y});
        while (!q.empty()){
            auto it = q.front();
            q.pop();
            if(it.first == d_x and it.second == d_y)break;
            for(int i = 0; i < 8; i++){
                int xx = it.first + dx[i], yy = it.second + dy[i];
                if(valid(xx, yy)){
                    dist[xx][yy] = min(dist[xx][yy], dist[it.first][it.second] + 1);
                    q.push({xx, yy});
                }
            }
        }
        cout << dist[d_x][d_y] << '\n';
    }
    return 0;
}
