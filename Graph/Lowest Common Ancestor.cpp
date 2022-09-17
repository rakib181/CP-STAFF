#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int> *l;
    public :
    Graph(int n){
        this -> V = n;
        this -> l = new list<int> [V];
    }

    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void print(){
        for(int i = 1; i < V; i++){
            cout << i << " -- >> ";
            for(auto x : l[i]){
                cout << x << ' ';
            }
            cout << '\n';
        }
    }

    void dfs(int cur, int par, vector<vector<int>> &lca, vector<int> &lvl, int log){
        lca[cur][0] = par;
        for(int i = 1; i <= log; i++){
           lca[cur][i] = lca[lca[cur][i - 1]][i - 1];
        }
        for(auto x : l[cur]){
            if(x != par){
                lvl[x] = lvl[cur] + 1;
                dfs(x, cur, lca, lvl, log);
            }
        }
    }

    int lowest_common_ancestor(int u, int v, vector<vector<int>> &lca, vector<int> &lvl, int log){
           if(lvl[u] < lvl[v]){
            swap(u, v);
           }
           if(u == v)return v;
           int dist = lvl[u] - lvl[v];
           while(dist){
             int i = log2(dist);
             u = lca[u][i];
             dist -= (1 << i);
           }
           for(int i = log; i >= 0; i--){
            if(lca[u][i] != lca[v][i]){
                u = lca[u][i];
                v = lca[v][i];
            }
           }
           return lca[v][0];
    }
};

int32_t main(){
     ios_base::sync_with_stdio(0);
      cin.tie(0); 
      #ifndef ONLINE_JUDGE 
      freopen("input.txt","r",stdin); 
      freopen("output.txt","w",stdout); 
      #endif
      auto start=clock();
      int n, m, log;
      cin >> n >> m;
      log = ceil(log2(n));
      vector<vector<int>> lca(n + 1, vector<int> (log + 1, -1));
      vector<int> lvl(n + 1, 0);
      Graph g(n + 1);
      for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
      }
      g.dfs(1, 1, lca, lvl, log); 
      cout << g.lowest_common_ancestor(11, 12, lca, lvl, log) << '\n';
      cout << g.lowest_common_ancestor(5, 9, lca, lvl, log) << '\n';
      cout << g.lowest_common_ancestor(6, 8, lca, lvl, log) << '\n';
      cout << g.lowest_common_ancestor(8, 10, lca, lvl, log) << '\n';
      cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
      return 0;
}
