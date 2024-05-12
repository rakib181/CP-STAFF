#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct two_sat{
    int n, cc;
    vector<vector<int>> g, rev;
    vector<int> comp, assignment;
    vector<bool> vis;
    stack<int> order;
    explicit two_sat(int n){
        this -> n = n;
        this -> cc = 0;
        this -> vis.assign(2 * n, false);
        this -> comp.assign(2 * n, -1);
        this -> assignment.assign(n, 0);
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
            assignment[i] = (comp[2 * i] > comp[2 * i + 1]);
        }
        return f;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, n;
    cin >> m >> n;
    two_sat sat(n);
    for(int i = 1; i <= m; i++){
        char na, nb;
        int a, b;
        cin >> na >> a >> nb >> b;
        a--, b--;
        sat.add_clause(a, na == '-', b, nb == '-');
    }
    sat.scc();
    bool satisfy = sat.satisfiability();
    if(!satisfy){
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    for(int i = 0; i < n; i++){
        cout << (sat.assignment[i] ? "+ " : "- ");
    }
    return 0;
}
