#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 1e5 + 9;
set<int> g[N];
vector<int> ans;

void dfs(int cur){
    while(!g[cur].empty()){
       auto x = *g[cur].begin();
       g[x].erase(cur);
       g[cur].erase(x);
       dfs(x);
    }
    ans.push_back(cur);
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].insert(v);
        g[v].insert(u);
    }
    for(int i = 1; i <= n; i++){
       if(g[i].size() & 1){
           cout << "IMPOSSIBLE" << '\n';
           return 0;
       }
    }
    dfs(1);
    if(ans.size() != m + 1){
        cout << "IMPOSSIBLE" << '\n';
        return 0;
    }
    reverse(ans.begin(), ans.end());
    for(auto x : ans){
        cout << x << ' ';
    }

    return 0;
}
