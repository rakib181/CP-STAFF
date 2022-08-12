#include <bits/stdc++.h>
using namespace std;

struct node
{
    node *t[26];
    bool isTerminal  = false;
};

class Trie{
    private : node *root;

    public :

    Trie(){
        root = new node();
    }
    
    void add(string s){
        node *tmp = root;
        for(auto x : s){
            if(tmp -> t[x - 'a'] == 0){
                tmp -> t[x - 'a'] = new node();
            }
            tmp = tmp -> t[x - 'a'];
        }
        tmp -> isTerminal = true;
    }

    bool isPrefixExist(string s){
        node *tmp = root;
        for(auto x : s){
            if(tmp -> t[x - 'a'] == 0){
                return false;
            }
            tmp = tmp -> t[x - 'a'];
            if(!tmp -> isTerminal) return false;
        }
        return tmp -> isTerminal;
    }

}tt;


int32_t main(){
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   int n;
   cin >> n;
   string s[n];
   for(int i = 0; i < n; i++){
    cin >> s[i];
    tt.add(s[i]);
   }
    string ans = "";
   for(auto x : s){
    if(tt.isPrefixExist(x)){
       if(x.size() > ans.size()){
        ans = x;
       }else if(x.size() == ans.size() && x < ans){
        ans = x;
       }
    }
   }
   if(ans == "")cout << "None" << '\n';
   else cout << ans << '\n';
    return 0;
}
