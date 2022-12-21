#include<bits/stdc++.h>
using namespace std;
#define int long long int
vector<vector<pair<int, int>>> g;

int DFS(int cur, int root){
    if(!cur)return 0;
    int s = 0;
    for(auto x : g[cur]){
        if(x.first == root)continue;
            s += DFS(x.first, cur) + x.second;
    }
    return s;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    g.resize(n + 1);
    for(int i = 0; i < n; i++){
        int u, v, c;
        cin >> u >> v >> c;
        --u, --v;
        g[u].emplace_back(v, 0);
        g[v].emplace_back(u, c);
    }
    cout << min(DFS(g[0][0].first, 0) + g[0][0].second, DFS(g[0][1].first, 0) + g[0][1].second) << '\n';
    return 0;
}
