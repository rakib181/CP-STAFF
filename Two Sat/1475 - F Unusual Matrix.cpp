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
        this -> n = n << 1;
        this -> cc = 0;
        this -> vis.assign(this -> n, false);
        this -> comp.assign(this -> n, -1);
        this -> g.assign(this -> n, vector<int> ());
        this -> rev.assign(this -> n, vector<int> ());
    }
    void add_clause(int a, bool na, int b, bool nb){
        a += a + !na;
        b += b + !nb;
        g[a].emplace_back(b);
        rev[b].emplace_back(a);
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
        for(int i = 0; i < n; i++){
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

    bool satisfiability() const{
        bool f = true;
        for(int i = 0; i + 1 < n; i += 2){
            f &= (comp[i] != comp[i + 1]);
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
        vector<string> a(n), b(n);
        for(int i = 0; i < n; i++)cin >> a[i];
        for(int i = 0; i < n; i++)cin >> b[i];
        two_sat sat(2 * n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int val = (a[i][j] - '0') ^ (b[i][j] - '0');
                if(val == 1){
                    sat.add_clause(i, false, j + n, true);
                    sat.add_clause(i, true, j + n, false);
                    sat.add_clause(j + n, false, i, true);
                    sat.add_clause(j + n, true, i, false);
                }else{
                    sat.add_clause(i, true, j + n, true);
                    sat.add_clause(i, false, j + n, false);
                    sat.add_clause(j + n, true, i, true);
                    sat.add_clause(j + n, false, i, false);
                }
            }
        }
        sat.scc();
        cout << (sat.satisfiability() ? "YES\n" : "NO\n");
    }
    return 0;
}
