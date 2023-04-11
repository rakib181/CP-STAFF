#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9, MX = 22;
vector<int> g[N];
int LCA[N][MX], depth[N], ans[N], X[N];

void dfs(int cur, int par){
    LCA[cur][0] = par;
    for(int i = 1; i < MX; i++){
        LCA[cur][i] = LCA[LCA[cur][i - 1]][i - 1];
    }
    for(auto x : g[cur]){
        if(x != par){
            depth[x] = depth[cur] + 1;
            dfs(x, cur);
        }
    }
}

int lca(int x, int y){
    if(depth[x] > depth[y])swap(x, y);
    for(int i = MX - 1; i >= 0 and depth[y] > depth[x]; i--){
        if(depth[LCA[y][i]] >= depth[x]) y = LCA[y][i];
    }

    if(x == y)return x;
    for(int i = MX - 1; i >= 0 and LCA[x][0] != LCA[y][0]; i--){
        if(LCA[y][i] != LCA[x][i]){
            x = LCA[x][i];
            y = LCA[y][i];
        }
    }
    return LCA[x][0];
}

int DFS(int cur, int par){
    int s = ans[cur];
    for(auto x : g[cur]){
        if(x != par){
           s += DFS(x, cur);
        }
    }
    X[cur] = s;
    return s;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    while(m--){
        int a, b, w;
        cin >> a >> b >> w;
        int _lca = lca(a, b);
        ans[a] += w;
        ans[b] += w;
        ans[_lca] -= w;
        if(LCA[_lca][0] != 0) ans[LCA[_lca][0]] -= w;
    }
    DFS(1, 0);
    int mx = INT_MAX, idx = 0;
    for(int i = 1; i <= n; i++){
        if(mx > X[i]){
            mx = X[i];
            idx = i;
        }
    }
    cout << idx << '\n';
    return 0;
}
