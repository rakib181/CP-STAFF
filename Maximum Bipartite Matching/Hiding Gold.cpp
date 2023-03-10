#include<bits/stdc++.h>
using namespace std;
#define int long long int

vector<int> dx = {0, 0, 1, -1}, dy = {1, -1, 0, 0};

struct BipartiteMatching{
    int n{}, m{};
    vector<int> *g{}, match;
    vector<bool> vis;
    void init(int _n, int _m){
        this -> n = _n;
        this -> m = _m;
        match.assign(n * m + 1, -1);
        vis.assign(n * m + 1, false);
        g = new vector<int> [n * m + 1];
    }

    void add_edge(int u, int v) const{
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int maxMatching(int node){
        int tot = 0;
        for(int i = 1; i <= node; i++){
            vis.assign(n * m + 1, false);
            if(kuhn(i)) tot += 1;
        }
        return tot;
    }
    bool kuhn(int v){
        if(vis[v])return false;
        vis[v] = true;
        for(auto x : g[v]){
            if(match[x] == -1 or kuhn(match[x])){
                match[x] = v;
                return true;
            }
        }
        return false;
    }
}G;


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt, cs = 1;
    cin >> tt;
    while (tt--){
        cout << "Case " << cs++ << ": ";
        int n, m, node = 1;
        cin >> n >> m;
        G.init(n, m);
        vector<vector<int>> g(n + 1, vector<int> (m + 1, 0));
        vector<vector<char>> grid(n + 1, vector<char> (m + 1));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cin >> grid[i][j];
                if(grid[i][j] == '*')g[i][j] = node, node += 1;
            }
        }
        auto valid = [&](int x, int y){
            return x >= 1 and x <= n and y >= 1 and y <= m;
        };
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(g[i][j]){
                    for(int x = 0; x < 4; x++){
                        int xx = i + dx[x], yy = j + dy[x];
                        if(valid(xx, yy) and g[xx][yy]){
                            G.add_edge(g[i][j], g[xx][yy]);
                        }
                    }
                }
            }
        }
        node -= 1;
        cout << node - (G.maxMatching(node) / 2) << '\n';
    }
    return 0;
}
