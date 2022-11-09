#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
vector<int> g[N];
vector<bool> vis(N, false);
int mx = 0;

void dfs(int cur, int par){
    for(auto x : g[cur]){
        if(x != par){
            dfs(x, cur);
            if(!vis[cur] and !vis[x]){
                vis[cur] = vis[x] = true;
                mx++;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, -1);
    cout << mx << '\n';
    return 0;
}
