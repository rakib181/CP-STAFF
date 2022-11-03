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
