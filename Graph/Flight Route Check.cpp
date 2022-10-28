#include <bits/stdc++.h>
using namespace std;

class GP{
public:
    int n;
    vector<int> *g;
    vector<bool> vis;
    void INIT(int _n){
        this -> n = _n;
        this -> g = new vector<int> [n];
        vis.resize(n, false);
    }

    void add_edge(int u, int v){
        g[u].push_back(v);
    }

    void dfs(int cur){
        vis[cur] = true;
        for(auto x : g[cur]){
            if(!vis[x]){
                dfs(x);
            }
        }
    }
}G1, G2;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    G1.INIT(n + 1), G2.INIT(n + 1);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        G1.add_edge(u, v);
        G2.add_edge(v, u);
    }
    G1.dfs(1);
    for(int i = 1; i <= n; i++){
        if(!G1.vis[i]){
            cout << "NO" << '\n';
            cout << 1 << ' ' << i << '\n';
            return 0;
        }
    }
    G2.dfs(1);
    for(int i = 1; i <= n; i++){
        if(!G2.vis[i]){
            cout << "NO" << '\n';
            cout << i << ' ' << 1 << '\n';
            return 0;
        }
    }
    cout << "YES" << '\n';
    return 0;
}
