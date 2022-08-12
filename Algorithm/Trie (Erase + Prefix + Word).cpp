#include<bits/stdc++.h>
using namespace std;

struct node{
node *t[26];
int ew = 0, cp = 0;
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
            if(tmp -> t[x - 'a'] == NULL){
                tmp -> t[x - 'a'] = new node();
            }
            tmp = tmp -> t[x - 'a'];
            tmp -> cp += 1;
        }
        tmp -> ew += 1;
    }

    int cwe(string s){
        node *tmp = root;
        for(auto x : s){
            if(tmp -> t[x - 'a'] == NULL){
                return 0;
            }
            tmp = tmp -> t[x - 'a'];
        }
        return tmp -> ew;
    }

    int getPref(string s){
        node *tmp = root;
        for(auto x : s){
            if(tmp -> t[x - 'a'] == NULL){
                return 0;
            }
            tmp = tmp -> t[x - 'a'];
        }
        return tmp -> cp;
    }

    void erase(string s){
        node *tmp = root;
        for(auto x : s){
            if(tmp -> t[x - 'a'] == NULL){
                return;
            }
            tmp = tmp -> t[x - 'a'];
            tmp -> cp -= 1;
        }
        tmp -> ew -= 1;
    }

}tt;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        tt.add(s);
    }
    cout << tt.cwe("ria") << '\n';
    cout << tt.getPref("rak") << '\n';
    tt.erase("rakib");
    cout << tt.cwe("rakib")<< '\n';
    return 0;
}
