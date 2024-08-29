#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 20000 + 9;
vector<bool> vis(N);
vector<int> comp(N), top;

void dfs(int u, vector<int> *g){
    vis[u] = true;
    for(auto v : g[u]){
        if(!vis[v]){
            dfs(v, g);
        }
    }
    top.emplace_back(u);
}


void dfs2(int u,int c, vector<int> *g){
    comp[u] = c;
    for(auto v : g[u]){
        if(!comp[v]){
            dfs2(v, c, g);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, cs = 1;
    cin >> t;
    while(t--) {
        cout << "Case " << cs++ << ": ";
        int n, m;
        cin >> n >> m;
        vector<int> g[n + 1], rev_g[n + 1]; top.clear();
        vector<pair<int, int>> edges;
        for(int i = 1; i <= n; i++){
            comp[i] = 0;
            vis[i] = false;
        }
        for (int i = 1; i <= m; i++) {
            int u, v;
            cin >> u >> v;
            g[u].emplace_back(v);
            rev_g[v].emplace_back(u);
            edges.emplace_back(u, v);
        }
        for(int i = 1; i <= n; i++){
            if(!vis[i]){
                dfs(i, g);
            }
        }
        reverse(top.begin(), top.end());
        int cnt = 0;
        for (auto v: top) {
            if (!comp[v]) {
                dfs2(v, ++cnt, rev_g);
            }
        }
        if(cnt == 1){
            cout << 0 << '\n';
            continue;
        }
        vector<int> in(cnt + 1, 0), out(cnt + 1, 0);
        int x = 0, y = 0;
        for(auto [u, v] : edges){
            if(comp[u] == comp[v])continue;
            in[comp[v]]++;
            out[comp[u]]++;
        }
        for(int i = 1; i <= cnt; i++){
            if(!in[i])x++;
            if(!out[i])y++;
        }
        cout << max(x, y) << '\n';
    }
    return 0;
}
