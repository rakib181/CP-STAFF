#include <bits/stdc++.h>
using namespace std;

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

void cal(int cur, int par, int n){
     if(par != 0){
         int vv = ans[par] - sub[cur] - sz[cur];
         int v = (vv + n + sub[cur] - sz[cur]);
         ans[cur] = v;
     }
     for(auto x : g[cur]){
         if(x != par){
             cal(x, cur, n);
         }
     }
}

vector<int> distanceSum(int n, vector<vector<int>> edges){
    g.assign(n + 1, vector<int> ());
    ans.assign(n + 1, 0), sub.assign(n + 1, 0), sz.assign(n + 1, 0);
     for(int i = 0; i < n - 1; i++){
         int u = edges[i][0], v = edges[i][1];
         g[u].push_back(v);
         g[v].push_back(u);
     }
     dfs(1, 0);
     ans[1] = sub[1];
     cal(1, 0, n);
     vector<int> wow;
     for(int i = 1; i <= n; i++){
         wow.push_back(ans[i]);
     }
    return wow;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n = 5;
    vector<vector<int>> edges = {{1, 2}, {1, 3}, {3, 4}, {3, 5}};
    vector<int> wow = distanceSum(n, edges);
    for(auto x : wow){
        cout << x << ' ';
    }
    return 0;
}
