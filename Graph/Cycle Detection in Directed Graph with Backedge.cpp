#include<bits/stdc++.h>
using namespace std;

class Graph{
   int V;
   bool cycle;
   list<int> *l;
   
   public :
   Graph(int v){
    this -> V = v;
    this -> cycle = false;
    this -> l = new list<int>[v];
   }
   void addEdge(int u, int v, bool undir = false){
       l[u].push_back(v);
       if(undir){
        l[v].push_back(u);
       }
   }
   void dfs(int src, vector<int> &visited, int par){
      visited[src] = 1;
      for(auto x : l[src]){
          if(!visited[x]){
            dfs(x, visited, src);
          }else if(x != par && visited[x] == 1){
            cycle = true;
            return;
          }
      }
      visited[src] = 2; 
   }

   bool isCycle(){
    vector<int> visited(V, 0);
    for(int i = 0; i < V; i++){
      if(!visited[i]){
        dfs(i, visited, -1);
      }
    }
    return cycle;
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
    Graph g(6);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    if(g.isCycle()){
      cout << "Cycle Found !" << '\n';
    }else{
      cout << "Cycle Not Found !" << '\n';
    }
    cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
    return 0;
}
