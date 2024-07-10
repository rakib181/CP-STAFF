#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int B = 18;

struct node{
    node *bit[2]{};
    node(){
        this -> bit[0] = nullptr;
        this -> bit[1] = nullptr;
    }
};



struct Trie{

     void insert(node *r, int v){
        node *t = r;
        for(int i = B - 1; i >= 0; i--){
            int b = (v >> i) & 1;
            if(t -> bit[b] == nullptr){
                t -> bit[b] = new node();
            }
            t = t -> bit[b];
        }
    }

    int max(node *r, int x){
        node *t = r;
        int ans = 0;
        for(int i = B - 1; i >= 0; i--){
            int b = (x >> i) & 1;
            if(t -> bit[b ^ 1]){
                ans |= (1 << i);
                t = t -> bit[b ^ 1];
            }else{
                t = t -> bit[b];
            }
        }
        return ans;
    }

     int min(node *r, int x){
        node *t = r;
        int ans = 0;
        for(int i = B - 1; i >= 0; i--){
            int b = (x >> i) & 1;
            if(t -> bit[b]){
                t = t -> bit[b];
            }else{
                ans |= (1 << i);
                t = t -> bit[b ^ 1];
            }
        }
        return ans;
    }

     void del(node *r){
        if(r -> bit[0]){
            del(r -> bit[0]);
        }
        if(r -> bit[1]){
            del(r -> bit[1]);
        }
        delete(r);
    }
}trie;



signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int l, r;
        cin >> l >> r;
        int n = (r - l + 1);
        vector<int> a(n);
        node *root = new node();
        for(int i = 0; i < n; i++){
            cin >> a[i];
            trie.insert(root, a[i]);
        }
        for(int i = 0; i < n; i++){
            int x = a[i] ^ l;
            if(trie.min(root, x) == l and trie.max(root, x) == r){
                cout << x << '\n';
                break;
            }
        }
        trie.del(root);
    }
    return 0;
}
