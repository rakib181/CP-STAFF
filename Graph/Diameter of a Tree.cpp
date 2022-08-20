#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
vector<int> gp[N];
vector<int> depth(N, 0);
int node, mx, dia;

void dfs(int cur, int par){
    depth[cur] = depth[par] + 1;
    if(depth[cur] > mx){
        mx = depth[cur];
        node = cur;
    }
    for(auto x : gp[cur]){
        if(x != par){
            dfs(x, cur);
        }
    }
}
void dfs1(int cur, int par){
    depth[cur] = depth[par] + 1;
    dia = max(dia, depth[cur] - 1);
    for(auto x : gp[cur]){
        if(x != par){
            dfs1(x, cur);
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)gp[i].clear(), depth[i] = 0;
    for(int i = 0 ; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        gp[u].push_back(v);
        gp[v].push_back(u);
    }
    node = 0, mx = 0;
    dfs(1, 0);
    for(int i = 1; i <= n; i++)depth[i] = 0;
     dia = 0;
    dfs1(node, 0);
    cout << dia << '\n';
    return 0;
}
