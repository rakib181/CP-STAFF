#include<bits/stdc++.h>
using namespace std;

class Graph{
     int V;
     list<int> *l;
  public :
  Graph(int v){
    this -> V = v;
    this -> l = new list<int>[V];
  }

  void addEdge(int u, int v, bool undir = true){
        l[u].push_back(v);
        if(undir){
          l[v].push_back(u);
        }
  }
  void printList(){
    for(int i = 1 ; i < V ; i++){
      cout << i << "--->";
      for(auto x : l[i]){
        cout << x << ' ';
      }
      cout << '\n';
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
    Graph gp(5);
    gp.addEdge(2, 4);
    gp.addEdge(1, 3);
    gp.addEdge(2, 3);
    gp.addEdge(1, 4);
    gp.addEdge(4, 3);
    gp.printList();
    cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
    return 0;
}
