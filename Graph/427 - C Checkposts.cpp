#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9, MOD = 1e9 + 7;
using ll = long long;
vector<int> g[N], rev[N], order, same;
vector<bool> vis(N);
int n, m, mn, C[N];

void dfs(int cur){
   vis[cur] = true;
   for(auto x : g[cur]){
       if(!vis[x]){
           dfs(x);
       }
   }
   order.push_back(cur);
}

void DFS(int cur){
    vis[cur] = true;
    same.push_back(C[cur]);
    mn = min(mn, C[cur]);
    for(auto x : rev[cur]){
        if(!vis[x]){
            DFS(x);
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> C[i];
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        rev[v].push_back(u);
    }
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    reverse(order.begin(), order.end());
    ll ans = 0, cnt = 1;
    vis.assign(n + 1, false);
    for(auto x : order){
        if(!vis[x]){
            same.clear();
            mn = INT_MAX;
            DFS(x);
            int c = 0;
            for(auto xx : same){
                if(xx == mn)c += 1;
            }
            ans += mn, cnt = cnt * c % MOD;
        }
    }
    cout << ans << ' ' << cnt << '\n';
    return 0;
}
