#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct two_sat{
    int n, cc;
    vector<vector<int>> g, rev;
    vector<int> comp;
    vector<bool> vis;
    stack<int> order;
    explicit two_sat(int n){
        this -> n = n;
        this -> cc = 0;
        this -> vis.assign(2 * n, false);
        this -> comp.assign(2 * n, -1);
        this -> g.assign(2 * n, vector<int> ());
        this -> rev.assign(2 * n, vector<int> ());
    }
    void add_clause(int a, bool na, int b, bool nb){
        int not_a = 2 * a + (na ? 0 : 1);
        int not_b = 2 * b + (nb ? 0 : 1);
        a = 2 * a + (na ? 1 : 0);
        b = 2 * b + (nb ? 1 : 0);
        g[not_a].emplace_back(b);
        g[not_b].emplace_back(a);
        rev[b].emplace_back(not_a);
        rev[a].emplace_back(not_b);
    }

    void dfs1(int u){
        vis[u] = true;
        for(auto v : g[u]){
            if(!vis[v]){
                dfs1(v);
            }
        }
        order.emplace(u);
    }

    void dfs2(int u, int c){
        comp[u] = c;
        for(auto v : rev[u]){
            if(comp[v] == -1){
                dfs2(v, c);
            }
        }
    }

    void scc(){
        for(int i = 0; i < 2 * n; i++){
            if(!vis[i]){
                dfs1(i);
            }
        }
        while(!order.empty()){
            auto u = order.top();
            order.pop();
            if(comp[u] == -1){
                dfs2(u, ++cc);
            }
        }
    }

    bool satisfiability(){
        bool f = true;
        for(int i = 0; i < n; i++){
            f &= (comp[2 * i] != comp[2 * i + 1]);
        }
        return f;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>> a(3, vector<int> (n));
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < n; j++){
                cin >> a[i][j];
            }
        }
        two_sat sat(n);
        for(int i = 0; i < n; i++){
            int x = a[0][i];
            int y = a[1][i];
            int z = a[2][i];
            sat.add_clause(abs(x) - 1, x > 0, abs(y) - 1, y > 0);
            sat.add_clause(abs(y) - 1, y > 0, abs(z) - 1, z > 0);
            sat.add_clause(abs(x) - 1, x > 0, abs(z) - 1, z > 0);
        }
        sat.scc();
        cout << (sat.satisfiability() ? "YES\n" : "NO\n");
    }
    return 0;
}
