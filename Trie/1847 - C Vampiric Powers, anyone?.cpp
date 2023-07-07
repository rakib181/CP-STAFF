#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct node{
public:
    int val;
    node *bit[2]{};
    node(){
        this -> val = 0;
        this -> bit[0] = nullptr;
        this -> bit[1] = nullptr;
    }
};

struct Trie{
public:
    node *root = new node();
    void insert(int x) const{
        node *tmp = root;
        for(int i = 31; i >= 0; i--){
            int v = ((x >> i) & 1);
            if(tmp -> bit[v] == nullptr){
                tmp -> bit[v] = new node();
            }
            tmp = tmp -> bit[v];
        }
        tmp -> val = x;
    }

    int query(int x) const{
        node *tmp = root;
        for(int i = 31; i >= 0; i--){
            int v = ((x >> i) & 1);
            if(tmp -> bit[1 - v] != nullptr){
                tmp = tmp -> bit[1 - v];
            }else if(tmp -> bit[v] != nullptr){
                tmp = tmp -> bit[v];
            }
        }
        return (x ^ tmp -> val);
    }
}trie;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
         int n;
         cin >> n;
         int pref = 0, ans = INT_MIN;
         trie.insert(pref);
         for(int i = 1; i <= n; i++){
             int x;
             cin >> x;
             pref ^= x;
             trie.insert(pref);
             ans = max(ans, trie.query(pref));
         }
         cout << ans << '\n';
         trie.root = new node();
    }
    return 0;
}
