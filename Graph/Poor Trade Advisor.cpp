#include <bits/stdc++.h>
using namespace std;
const int N = 509;
vector<pair<int, int>> g[N];
vector<bool> vis(N);

int DFS(int cur, int mx){
    int cnt = 1;
    for(auto x : g[cur]){
       if(!vis[x.first] and x.second == mx){
           vis[x.first] = true;
           int sub = DFS(x.first, mx);
           cnt += sub;
       }
    }
    return cnt;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    while (cin >> n >> m, n and m){
        for(int i = 0; i < N; i++){
            g[i].clear();
            vis[i] = false;
        }
        int ans = 0, mx = INT_MIN;
        for(int i = 0; i < m; i++){
            int u, v, w;
            cin >> u >> v >> w;
            g[u].emplace_back(v, w);
            g[v].emplace_back(u, w);
            mx = max(mx, w);
        }
        for(int i = 1; i <= n; i++){
            if(!vis[i]){
                vis[i] = true;
                ans = max(ans, DFS(i, mx));
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
