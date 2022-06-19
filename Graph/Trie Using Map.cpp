#include<bits/stdc++.h>
using namespace std;

class Node{
public:
  char s;
  map<char, Node*> children;
  bool isTerminal;

  Node(char s){
    this -> s = s;
    isTerminal = false;
  }
};

class Trie{
public:
  Node *root;
  Trie(){
    root = new Node('\0');
  }

  void addWord(string s){
    Node *tmp = root;
    for(auto ch : s){
      if(tmp -> children.count(ch) == 0){
         tmp -> children[ch] = new Node(ch);
      }
      tmp = tmp -> children[ch];
    }
    tmp -> isTerminal = true;
  }

  bool search(string s){
    Node *tmp = root;
    for(auto ch : s){
      if(tmp -> children[ch] == NULL){
        return false;
      }
      tmp = tmp -> children[ch];
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
    int n;
    cin >> n;
    string s[n];
    for(int i = 0; i < n; i++){
      cin >> s[i];
    }
    for(int i = 0;i < n; i++){
      t.addWord(s[i]);
    }
    if(t.search("rakib")){
      cout << "Found !" << '\n';
    }else{
      cout << "Not Found !" << '\n';
    }
    cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
    return 0;
}
