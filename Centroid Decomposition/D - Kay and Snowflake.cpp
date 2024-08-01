#include<bits/stdc++.h>
using namespace std;

#define long long long int

const int N = 3e5 + 9;
vector<int> g[N], sz(N), centroid(N);

void cal(int u){
    sz[u] = 1;
    for(auto v : g[u]){
        cal(v);
        sz[u] += sz[v];
    }
}

set<pair<int, int>> dfs(int u){
    set<pair<int, int>> cur;
    for(auto v : g[u]){
       auto ch = dfs(v);
       if(ch.size() > cur.size()){
           swap(ch, cur);
       }
       for(auto c : ch){
           cur.emplace(c);
       }
    }
    cur.emplace(sz[u], u);
    centroid[u] = cur.lower_bound({(sz[u] + 1) / 2, 0}) -> second;
    return cur;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    for(int v = 2; v <= n; v++){
        int u;
        cin >> u;
        g[u].emplace_back(v);
    }
    cal(1);
    dfs(1);
    while(q--){
        int v;
        cin >> v;
        cout << centroid[v] << '\n';
    }
    return 0;
}
