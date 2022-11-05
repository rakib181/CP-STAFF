#include<bits/stdc++.h>
using namespace std;

#define int long long int
const int N = 505;
int g[N][N];
bool vis[N];
int par[N];

bool reachable(int n){
    memset(vis, false, sizeof (vis));
    queue<int> q;
    q.push(1);
    vis[1] = true;
    while (!q.empty()){
        int node = q.front();
        q.pop();
        for(int x = 1; x <= n; x++){
            if(!vis[x] and g[node][x]){
                q.push(x);
                par[x] = node;
                vis[x] = true;
            }
        }
    }
    return vis[n];
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        g[u][v] += w;
    }
    int max_flow = 0, t, x;
    while(reachable(n)){
        int flow = 1e18;
        t = n;
        while(t != 1){
            x = par[t];
            flow = min(flow, g[x][t]);
            t = x;
        }
        max_flow += flow;
        t = n;
        while(t != 1){
            x = par[t];
            g[x][t] -= flow;
            g[t][x] += flow;
            t = x;
        }
    }
    cout << max_flow << '\n';
    return 0;
}

// Again
#include<bits/stdc++.h>
using namespace std;

bool reachable(int n, vector<vector<long long>> &g, vector<int> &par){
   vector<bool> vis(n + 1, false);
   queue<int> q;
   q.push(1);
   vis[1] = true;
   while(!q.empty()){
      int node = q.front();
      q.pop();
      for(int i = 1; i <= n; i++){
         if(!vis[i] and g[node][i]){
            q.push(i);
            par[i] = node;
            vis[i] = true;
         }
      }
   }
   return vis[n];
}

long long solve(int n, vector<vector<int>> edges)
{
    vector<vector<long long> > g (n + 1, vector<long long> (n + 1, 0));
    vector<int> par(n + 1, 0);
    for(int i = 0; i < (int) edges.size(); i++){
      long long u = edges[i][0], v = edges[i][1], w = edges[i][2];
      g[u][v] += w;
    }
    long long flow = 0, t, x;
    while(reachable(n, g, par)){
       long long new_flow = 1e18;
       t = n;
       while(t != 1){
         x = par[t];
         new_flow = min<long long> (new_flow, g[x][t]);
         t = x;
       }
       flow += new_flow;
       t = n;
       while(t != 1){
         x = par[t];
         g[x][t] -= new_flow;
         g[t][x] += new_flow;
         t = x;
       }
    }
    return flow;
}

int main(){
   int n = 4;
   vector<vector<int>> edges = {
        {1, 2, 3}, {2, 4, 2},
        {1, 3, 4}, {3, 4, 5},
        {4, 1, 3}
   };
   cout << solve(n, edges) << '\n';
}
