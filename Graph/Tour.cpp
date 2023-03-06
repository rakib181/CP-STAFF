#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 2005;
vector<int> g[N];
vector<bool> vis;
int dfs(int cur){
    if(vis[cur]){
        return 0;
    }
    vis[cur] = true;
    int sz = 1;
    for(auto x : g[cur]){
        sz += dfs(x);
    }
    return sz;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        vis.assign(n + 1, false);
        int sz = dfs(i);
        ans += sz;
    }
    cout << ans << '\n';
    return 0;
}
