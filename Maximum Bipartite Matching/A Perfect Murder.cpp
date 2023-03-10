#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int MX = 1009;

struct BipartiteMatching{
    int n{};
    vector<vector<int>> g;
    vector<bool> vis;
    vector<int> match;
    void init(int _n){
        this -> n = _n;
        g.assign(MX, vector<int> (MX, 0));
        vis.assign(MX, false);
        match.assign(MX, -1);
    }

    bool kuhn(int v){
        if(vis[v])return false;
        vis[v] = true;
        for(int i = 1; i <= n; i++){
            if(g[v][i]) {
                if (match[i] == -1 or kuhn(match[i])) {
                    match[i] = v;
                    return true;
                }
            }
        }
        return false;
    }

    void add_edge(int u, int v){
        g[u][v] = 1;
        g[v][u] = 1;
    }

    int Max_Matching(){
        int tot = 0;
        for(int i = 1; i <= n; i++){
            vis.assign(MX, false);
            if(kuhn(i)) tot += 1;
        }
        return tot;
    }
}G;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt, cs = 1;
    cin >> tt;
    while (tt--) {
        cout << "Case " << cs++ << ": ";
        int n, m;
        cin >> n >> m;
        G.init(n);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            G.add_edge(u, v);
        }
        cout << n - G.Max_Matching() / 2 << '\n';
    }
    return 0;
}
