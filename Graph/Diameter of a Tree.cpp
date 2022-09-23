#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
vector<int> g[N];
vector<int> depth(N, 0);

void dfs(int cur, int par = 0){
    for(auto x : g[cur]){
        if(x != par){
            depth[x] = depth[cur] + 1;
            dfs(x, cur);
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    int node = 0, mx = INT_MIN;
    for(int i = 1; i <= n; i++){
        if(depth[i] > mx)mx = depth[i], node = i;
        depth[i] = 0;
    }
    dfs(node); mx = INT_MIN;
    for(int i = 1; i <= n; i++)if(depth[i] > mx)mx = depth[i];
    cout << mx << '\n';
    return 0;
}

