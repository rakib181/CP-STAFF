#include<bits/stdc++.h>
using namespace std;

class Graph{
   public :
   int V;
   list<int> *l;
    int *dist;
   Graph(int v){
    this -> V = v;
    this -> l = new list<int>[v];
    this -> dist = new int[v];
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
    dist[src] = 0;
    while(!q.empty()){
      int f = q.front();
      q.pop();
      for(auto cur : l[f]){
        if(!vis[cur]){
          q.push(cur);
          vis[cur] = true;
          dist[cur] = dist[f] + 1;
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
    for(int i = 0; i < 7; i++){
      cout << g.dist[i] << ' ';
    }
    cout << '\n';
    cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
    return 0;
}
