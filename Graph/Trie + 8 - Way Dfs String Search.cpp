#include<bits/stdc++.h>
using namespace std;

#define N 3
#define M 4

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool vis[N][M];

class Node{
  public:
    char s;
    map<char, Node*> children;
    bool isTerminal;
    string word;
    Node(char c){
      this -> s = c;
      isTerminal = false;
      word = "";
    }
};

class Trie{
public:
  Node *root;
  Trie(){
    root = new Node('\0');
  }
  void addword(string word){
    Node *tmp = root;
    for(auto c : word){
      if(tmp -> children.count(c) == 0){
        tmp -> children[c] = new Node(c);
      }
      tmp = tmp -> children[c];
    }
    tmp -> isTerminal = true;
    tmp -> word = word;
  }
};

void dfs(char c[N][M], Node *node, int x, int y, unordered_set<string> &output){
  char ch = c[x][y];
     if(node -> children.count(ch) == 0){
      return;
     }
    
    vis[x][y] = true;
    node = node -> children[ch];

     if(node -> isTerminal){
      output.insert(node -> word);
     }

     for(int i = 0; i < 8; i++){
        int _x = x + dx[i]; int  _y = y + dy[i];
        if(_x >= 0 && _y >= 0 && _x < N && _y < M && !vis[_x][_y]){
          dfs(c, node, _x, _y, output);
        }
     }


     vis[x][y] = false;
}

int32_t main(){
   ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
    #ifndef ONLINE_JUDGE 
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    #endif
    auto start=clock();
    string word[8] = {"SNAKE", "FOR", "QUEZ", "SNACK", "SNACKS", "SENS", "TUNES", "CAT"};
    char ch[N][M] = {{'S', 'E', 'R', 'T'},
                     {'U', 'N', 'K', 'S'},
                     {'T', 'C', 'A', 'T'}};

        Trie t;
        for(auto x : word){
          t.addword(x);
        }
        unordered_set<string> output;
        for(int i = 0; i < N; i++){
          for (int j = 0; j < M; j++){
             dfs(ch, t.root, i, j, output);
          }
        }

        for(auto x : output){
          cout << x << ' ';
        }
        cout << '\n';


    cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
    return 0;
}
