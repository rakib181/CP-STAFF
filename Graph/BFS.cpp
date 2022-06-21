#include<bits/stdc++.h>
using namespace std;

class Graph{
   int V;
   list<int> *l;
   
   public :
   Graph(int v){
    this -> V = v;
    this -> l = new list<int>[v];
   }
   void addEdge(int u, int v, bool undir = true){
       l[u].push_back(v);
       if(undir){
        l[v].push_back(u);
       }
   }

   void bfs(int src){
    queue<int> q;
    bool vis[V]{0};
    q.push(src);
    vis[src] = true;
    while(!q.empty()){
      int f = q.front();
      cout << f << '\n';
      q.pop();
      for(auto cur : l[f]){
        if(!vis[cur]){
          q.push(cur);
          vis[cur] = true;
        }
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

    Graph g(7);
    g.addEdge(1, 2);
    g.addEdge(1, 0);
    g.addEdge(2, 3);
    g.addEdge(0, 4);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(5, 6);
    g.bfs(1);
    
    cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
    return 0;
}
