#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
vector<int> g[N];
vector<bool> vis(N, false);

void DFS(int cur, vector<int>  &comp){
    vis[cur] = true;
    comp.push_back(cur);
    for(auto x : g[cur]){
        if(!vis[x]){
            DFS(x, comp);
        }
    }
}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> deg(n + 1, 0);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++, deg[v]++;
    }
    vector<int> comp; int v_cc = 0;
    for(int i = 1; i <= n; i++){
        comp.clear();
        if(deg[i] == 2 and !vis[i]) {
            DFS(i, comp);
            bool ok = true;
            for (auto x: comp) {
                if (deg[x] != 2) {
                    ok = false;
                    break;
                }
            }
            if (ok)v_cc++;
        }
    }
    cout << v_cc << '\n';
    return 0;
}
