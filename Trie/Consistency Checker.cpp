#include<bits/stdc++.h>
using namespace std;

struct node{
    node *ar[10];
    bool isTerminal;
    node(){
        for(int i = 0; i < 10; i++){
           this -> ar[i] = 0;
        }
        this -> isTerminal = false;
    }
} *root;

class Trie{
public:
    void add(string s){
        node *tmp = root;
        for(auto x : s){
            int ch = (x - '0');
            if(tmp -> ar[ch] == 0) tmp -> ar[ch] = new node();
            tmp = tmp -> ar[ch];
        }
        tmp -> isTerminal = true;
    }

    bool isFound(node* tmp){
        for(int i = 0; i < 10; i++){
            if(tmp -> ar[i] != 0) {
                if (tmp->isTerminal) return true;
                if (isFound(tmp->ar[i])) return true;
            }
        }
        return false;
    }

    void del(node* tmp){
        for(int i = 0; i < 10; i++){
            if(tmp -> ar[i] != 0){
                del(tmp -> ar[i]);
            }
        }
        delete(tmp);
    }

}trie;

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt, idx = 1;
    cin >> tt;
    while (tt--){
        cout << "Case " << idx++ << ": ";
        int n;
        cin >> n;
        root = new node();
        for(int i = 0; i < n; i++){
            string s;
            cin >> s;
            trie.add(s);
        }
        if(trie.isFound(root)){
            cout << "NO\n";
        }else{
            cout << "YES\n";
        }
        trie.del(root);
    }
    return 0;
}
