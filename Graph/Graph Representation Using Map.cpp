#include<bits/stdc++.h>
using namespace std;

class Node{
  public :
  string name;
  list<string> nbrs;
  Node(string name){
    this -> name = name;
  }
};

class Graph{
   map<string, Node*> m;
   public :
   Graph(vector<string> cities){
   for(auto city : cities){
    m[city] = new Node(city);
     }
   }
   void addEdge(string u, string v, bool undir = false){
    m[u] -> nbrs.push_back(v);
    if(undir){
      m[v] -> nbrs.push_back(u);
    }
   }
   void printList(){
    for(auto x : m){
      auto city = x.first;
      Node *node = x.second;
      cout << city << "--->";
      for(auto l : node -> nbrs){
        cout << l << ' ';
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

    vector<string> cities = {"Dhaka", "Delhi", "Dubai", "Washinton"};
    Graph g(cities);
    g.addEdge("Dhaka", "Delhi");
    g.addEdge("Dhaka", "Washinton");
    g.addEdge("Dubai", "Delhi");
    g.addEdge("Washinton", "Dubai");
    g.addEdge("Delhi", "Washinton");
    g.printList();
    
    cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
    return 0;
}
