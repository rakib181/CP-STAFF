#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    char ch;
    map<char, Node*> mp;
    bool isTerminal;
    explicit Node(char _ch){
        this -> ch = _ch;
        this -> isTerminal = false;
    }
};

class Trie{
public:
    Node *root;
    Trie(){
        this -> root = new Node('\0');
    }
    void insert(const string& s) const{
        Node *tmp = root;
        for(auto ch : s){
            if(tmp -> mp.count(ch) == 0){
                tmp -> mp[ch] = new Node(ch);
            }
            tmp = tmp -> mp[ch];
        }
        tmp -> isTerminal = true;
    }

    void search(string &document, int i, unordered_map<string, bool> &m) const{
         Node *tmp = root;
         for(int j = i; j < document.size(); j++){
             char c = document[j];
             if(tmp -> mp.count(c) == 0){
                 return;
             }
             tmp = tmp -> mp[c];
             if(tmp -> isTerminal){
                 string out = document.substr(i, j - i + 1);
                 m[out] = true;
             }
         }
    }

    void document_search(string &document, vector<string> &word){
          for(const auto& w : word){
              insert(w);
          }
          unordered_map<string, bool> m;
          for(int i = 0; i < document.size(); i++){
              search(document, i, m);
          }
        for(auto w : word){
            if(m[w]){
                cout << "Found !" << '\n';
            }else cout << "Not Found !" << '\n';
        }
    }
}T;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; //little cat loves to code in c++, java & python
    getline(cin , s);
    vector<string> word = {"cute cat", "ttle", "cat", "quick", "big"};
    T.document_search(s, word);
    return 0;
}
