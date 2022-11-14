#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 2e5 + 1, LOG = 20;
vector<int> g[N];
vector<vector<int>> P(N, vector<int> (LOG, 0));
vector<int> dist(N, 0), dp(N, 0);
void dfs(int cur, int par){
    P[cur][0] = par;
    for(int i = 1; i < LOG; i++){
        P[cur][i] = P[P[cur][i - 1]][i - 1];
    }
    for(auto x : g[cur]){
        if(x != par){
            dist[x] = dist[cur] + 1;
            dfs(x, cur);
        }
    }
}

int LCA(int u, int v){
    if(dist[u] < dist[v]){
        swap(u, v);
    }
    if(u == v)return v;
    int d = dist[u] - dist[v];
    for(int i = 0; i < LOG; i++){
        if((d >> i) & 1){
            u = P[u][i];
        }
    }
    if(u == v)return v;
    for(int i = LOG - 1; i >= 0; i--){
        if(P[u][i] != P[v][i]){
            u = P[u][i], v = P[v][i];
        }
    }
    return P[u][0];
}

void dfs1(int cur, int par){
    for(auto x : g[cur]){
        if(x != par){
            dfs1(x, cur);
            dp[cur] += dp[x];
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    while (m--){
        int u, v;
        cin >> u >> v;
        dp[u]++, dp[v]++, dp[P[LCA(u, v)][0]]--, dp[LCA(u, v)]--;
    }
    dfs1(1, 0);
    for(int i = 1; i <= n; i++){
        cout << dp[i] << ' ';
    }
    return 0;
}
