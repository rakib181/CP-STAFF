#include<bits/stdc++.h>
using namespace std;

int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

int minCost(vector<vector<int>> grid)
{
    int n = (int) grid.size(), m = (int) grid[0].size();
    vector<vector<int>> dist(n + 1, vector<int> (m + 1, INT_MAX));
    deque<pair<pair<int, int>, int>> dq;
    dq.push_front({{0, 0}, 0});
    dist[0][0] = 0;
    while(!dq.empty()){
        auto x = dq.front();
        dq.pop_front();
        int xx = x.first.first, yy = x.first.second, val = x.second;
        if(xx == n - 1 and yy == m - 1){
            break;
        }
        for(int i = 0; i < 4; i++){
            int xxx = xx + dx[i], yyy = yy + dy[i];
            int dir = i + 1;
            if(xxx >= 0 and xxx < n and yyy >= 0 and yyy < m){
                int flag = 0;
                if(grid[xx][yy] != dir){
                    flag = 1;
                }
                if(dist[xxx][yyy] > val + flag){
                    if(flag){
                        dq.push_back({{xxx, yyy}, val + flag});
                    }else{
                        dq.push_front({{xxx, yyy}, val});
                    }
                }
                dist[xxx][yyy] = min(dist[xxx][yyy], val + flag);
            }
        }
    }
    return dist[n - 1][m - 1];
}
int main(){
    vector<vector<int>> grid = {
            {1,1,1,1},{2,2,2,2},{1,1,1,1},{2,2,2,2}
    };
    cout << minCost(grid) << '\n';
}
