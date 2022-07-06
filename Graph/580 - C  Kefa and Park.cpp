#include<bits/stdc++.h>
using namespace std;

const int N = 1e6;

int n, m, k, ans = 0;
int bin[N], vis[N], deg[N];

class Graph{
   list<int> *l;
   public :
    Graph(){
    this -> l = new list<int>[N];
   }
   void addEdge(int u, int v){
       l[u].push_back(v);
       l[v].push_back(u);
        deg[u]++;
        deg[v]++; 
   }
   void dfs(int src, int res, int mx){
   vis[src] = 1;  
   if(src > 1 && deg[src] == 1 && mx <= m){
     ans++;
   }
    for(auto u : l[src]){
      if(!vis[u]){
        int mX = max(mx, res + bin[u]);
        if(bin[u])dfs(u, res + 1, mX);
        else dfs(u, 0, mX);
       }
     }
   }
};

int32_t main(){
   ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
    #ifndef ONLINE_JUDGE 
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    #endif
    auto start=clock();
    cin >> n >> m;
    Graph gp;
    for(int i = 1; i <= n; i++){
      cin >> bin[i];
    }
     k = n - 1;
    while(k--){
      int x, y;
      cin >> x >> y;
      gp.addEdge(x, y); 
    }
     if(bin[1])gp.dfs(1, 1, 1);
     else gp.dfs(1, 0, 0);
     cout << ans << '\n';
    cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
    return 0;
}
