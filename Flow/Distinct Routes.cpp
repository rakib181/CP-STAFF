#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
vector<vector<int>> res;

int bfs(vector<vector<int>> &cap, int s, int t, vector<int> &par){
    queue<pair<int, int>> q;
    q.push({s, INT_MAX});
    par.assign(n + 1, -1);
    par[s] = -2;
    while(!q.empty()){
        int node = q.front().first;
        int flow = q.front().second;
        q.pop();
        for(int i = 1; i <= n; i++){
            if(par[i] == -1 and cap[node][i]){
                par[i] = node;
                int new_flow = min<long long>(flow, cap[node][i]);
                if(i == t)return new_flow;
                q.push({i, new_flow});
            }
        }
    }
    return 0;
}
int Max_flow(vector<vector<int>> &graph, int s, int t){
    vector<int> parent;
    int flow = 0, new_flow;
    res.resize(n + 1, vector<int> (n + 1, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            res[i][j] = graph[i][j];
        }
    }
    new_flow = bfs(res, s, t, parent);
    while(new_flow){
        flow += new_flow;
        int cur = t;
        while(cur != s){
            int prev = parent[cur];
            res[prev][cur] -= new_flow;
            res[cur][prev] += new_flow;
            cur = prev;
        }
        new_flow = bfs(res, s, t, parent);
    }
    return flow;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    vector<vector<int>> g(n + 1, vector<int> (n + 1, 0));
    set<int> gr[n + 1];
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        g[a][b] += 1;
        gr[a].insert(b);
    }
    int sz = Max_flow(g, 1, n);
    cout << sz << '\n';
    for(int i = 0; i < sz; i++){
          vector<int> path;
          path.push_back(1);
          int x = 1;
          while(x != n){
              for(auto xx : gr[x]){
                  if(g[x][xx] and !res[x][xx]){
                      path.push_back(xx);
                      g[x][xx] -= 1;
                      x = xx;
                  }
              }
          }
          cout << path.size() << '\n';
          for(auto xx : path){
              cout << xx << ' ';
          }
          cout << '\n';
    }
    return 0;
}
