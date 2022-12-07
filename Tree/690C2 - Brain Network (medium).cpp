#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
vector<int> g[N];
vector<int> depth(N, 0);
int n, m,root, mx;

void DFS(int cur, int par){
    for(auto x: g[cur]){
        if(x != par){
            depth[x] = depth[cur] + 1;
            DFS(x, cur);
        }
    }
}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        root = u;
    }
    DFS(root, -1);
    mx = INT_MIN;
    for(int i = 1; i <= n; i++){
        if(depth[i] > mx)mx = depth[i], root = i;
        depth[i] = 0;
    }
    DFS(root, -1);
    mx = INT_MIN;
    for(int i = 1; i <= n; i++){
        if(depth[i] > mx)mx = depth[i];
    }
    cout << mx << '\n';
    return 0;
}
