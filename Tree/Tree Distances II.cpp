#include <bits/stdc++.h>
using namespace std;
#define int long long int
int n;
vector<vector<int>> g; vector<int> sz, sub, ans;
void dfs(int cur, int par){
    sz[cur] = 1, sub[cur] = 0;
    for(auto x : g[cur]){
        if(x != par){
            dfs(x, cur);
            sz[cur] += sz[x];
            sub[cur] += (sub[x] + sz[x]);
        }
    }
}

void cal(int cur, int par){
     if(par != 0){
         int vv = ans[par] - sz[cur];
         int v = (vv + n - sz[cur]);
         ans[cur] = v;
     }
     for(auto x : g[cur]){
         if(x != par){
             cal(x, cur);
         }
     }
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    g.assign(n + 1, vector<int>());
    ans.assign(n + 1, 0), sub.assign(n + 1, 0), sz.assign(n + 1, 0);
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    ans[1] = sub[1];
    cal(1, 0);
    for(int i = 1; i <= n; i++){
        cout << ans[i] << ' ';
    }
    return 0;
}
