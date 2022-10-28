#include<bits/stdc++.h>
using namespace std;

int n, m;
int dx[] = {0, -1, 1, 0, -1, 1}, dy[] = {-1, -1, -1, 1, 1, 1};
vector<vector<int>> g;
int s, t, flow;

void BFS(vector<int> &parent){
    queue<int> q;
    q.push(s);
    vector<bool> vis(n * m + 2, false);
    vis[s] = true;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int i = 0; i < n * m + 2; i++){
            if(!vis[i] and g[node][i]){
                vis[i] = true;
                q.push(i);
                parent[i] = node;
            }
        }
    }
}

void Edmond_Karp(){
    while(true){
        vector<int> parent(n * m + 2, -1);
        BFS(parent);
        if(parent[t] == -1)break;
        int tt = t;
        while(true){
            int u = parent[tt];
            g[u][tt]--;
            g[tt][u]++;
            tt = u;
            if(tt == s)break;
        }
        flow++;
    }
}

int maxStudents(vector<vector<char>> seats) {
    n = (int) seats.size();
    m = (int) seats[0].size();
    g.resize(n * m + 2, vector<int> (n * m + 2, 0));
    s = n * m, t = s + 1;
    int tot_seat = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(seats[i][j] == '#')continue;
            tot_seat++;
            if(!(j & 1)) {
                g[s][i * m + j] = 1;
                for (int k = 0; k < 6; k++) {
                    int nx = i + dx[k], ny = j + dy[k];
                    if (nx < 0 or nx >= n or ny < 0 or ny >= m or seats[nx][ny] == '#')continue;
                    g[i * m + j][nx * m + ny] = 1;
                }
            }else{
                g[i * m + j][t] = 1;
            }
        }
    }
    flow = 0;
    Edmond_Karp();
    return tot_seat - flow;
}

int main(){
    vector<vector<char>> sss = {
            {'#', '.', '#', '#', '.', '#'},
            {'.', '#', '#', '#', '#', '.'},
            {'#', '.', '#', '#', '.', '#'}
    };
    cout << maxStudents(sss) << '\n';
    return 0;
}
