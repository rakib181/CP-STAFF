#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
vector<int> g[N];
vector<bool> vis(N, false), team(N, false);
bool possible;

void dfs(int cur, int par){
    vis[cur] = true;
    for(auto x : g[cur]){
        if(x != par and !vis[x]){
            team[x] = !team[cur];
            dfs(x, cur);
        }else{
            if(team[x] == team[cur])possible = false;
        }
    }
}

int32_t main(){
   ios_base::sync_with_stdio(0);
    cin.tie(0); 
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
      int u, v;
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    possible = true;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            dfs(i, -1);
        }
    }
    if(!possible)cout << "IMPOSSIBLE" << '\n';
    else{
        for(int i = 1; i <= n; i++){
            if(!team[i])cout << "1" << ' ';
            else cout << "2" << ' ';
        }
    }

    return 0;
}
