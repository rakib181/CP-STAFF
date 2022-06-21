#include<bits/stdc++.h>
using namespace std;

struct Node{
   char c;
   map<char, Node*> children;
   bool isTerminal;
   Node(char ch){
    this -> c = ch;
    isTerminal = false;
   }
};

class Trie{
  public :
  Node *root;
  Trie(){
    root = new Node('\0');
  }
  void addWord(string s){
    Node *tmp = root;
    for(auto x : s){
        if(tmp -> children.count(x) == 0){
          tmp -> children[x] = new Node(x);
        }
        tmp = tmp -> children[x];
    }
    tmp -> isTerminal = true;
  }

  bool search(string s){
    Node *tmp = root;
    for(auto x : s){
      if(tmp -> children.count(x) == 0){
        return false;
      }
     tmp =  tmp -> children[x];
    }
    return tmp -> isTerminal;
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
    Trie t;
    string word[] = {"abir", "riana", "nuaira", "niba", "anna"};
    for(auto x : word){
        t.addWord(x);
    }
    if(t.search("riana")){
      cout << "Found !" << '\n';
    }else{
      cout << "Not Found !" << '\n';
    }
    cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
    return 0;
}
