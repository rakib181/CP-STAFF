#include<bits/stdc++.h>
using namespace std;
#define long long long int

const int N = 1e3 + 9;
vector<int> g[N], parent(N), d(N, -1), nodes;

void dfs(int u, int p, int dis = 0){
    nodes.emplace_back(u);
    parent[u] = p;
    d[u] = dis;
    for(auto v : g[u]){
        if(v == p)continue;
        dfs(v, u, dis + 1);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    vector<pair<int, int>> diameter;
    for(int i = 1; i <= n; i++){
        if(d[i] == -1){
            int node = i;
            nodes.clear();
            dfs(node, 0);
            int mx = 0;
            for(auto v : nodes){
                if(d[v] >= mx){
                    mx = d[v];
                    node = v;
                }
                d[v] = -1;
            }
            nodes.clear();
            dfs(node, 0);
            mx = 0;
            for(auto v : nodes){
                if(d[v] >= mx){
                    mx = d[v];
                    node = v;
                }
            }
            int distance = mx / 2;
            while (node and distance > 0){
                node = parent[node];
                distance--;
            }
            diameter.emplace_back(mx, node);
        }
    }
    sort(diameter.begin(), diameter.end());
    int sz = (int) diameter.size();
    int ans = diameter.back().first;
    if(sz > 1){
        ans = max(ans, (diameter[sz - 2].first + 1) / 2 + (diameter[sz - 1].first + 1) / 2 + 1);
    }
    if(sz > 2){
        ans = max(ans, (diameter[sz - 3].first + 1) / 2 + (diameter[sz - 2].first + 1) / 2 + 2);
    }
    cout << ans << '\n';
    for(int i = 0; i < sz - 1; i++){
        cout << diameter[i].second << ' ' << diameter[sz - 1].second << '\n';
    }
    return 0;
}
