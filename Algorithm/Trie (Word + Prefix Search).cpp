#include<bits/stdc++.h>
using namespace std;

struct node{
    node *t[26];
    bool isTerminal = false;
};

class Trie{
private:   node *root;

public:
    Trie(){
        root = new node();
    }
    void add(string s){
        node* tmp = root;
        for(auto x : s){
            if(tmp -> t[x - 'a'] == NULL){
                tmp -> t[x - 'a'] = new node();
            }
            tmp = tmp -> t[x - 'a'];
        }
        tmp -> isTerminal = true;
    }

    bool search(string s){
        node* tmp = root;
        for(auto x : s){
            if(tmp -> t[x - 'a'] == NULL){
                return false;
            }
            tmp = tmp -> t[x - 'a'];
        }
        return tmp -> isTerminal;
    }

    bool isPrefix(string s){
        node *tmp = root;
        for(auto x : s){
            if(tmp -> t[x - 'a'] == NULL){
                return false;
            }
            tmp = tmp -> t[x - 'a'];
        }
        return true;
    }
}tt;

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
     int n, q;
     cin >> n >> q;
     for(int i = 0; i < n; i++){
         string s;
         cin >> s;
         tt.add(s);
     }
     while(q--){
         int x;
         cin >> x;
         if(x == 1) {
             string s;
             cin >> s;
             cout << tt.search(s) << '\n';
         }else{
             string s;
             cin >> s;
             cout << tt.isPrefix(s) << '\n';
         }
     }
    return 0;
}
