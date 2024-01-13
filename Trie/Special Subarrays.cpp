#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;

struct node{
    int data;
    node *hash[2]{};
        explicit node(int d){
            this -> data = d;
            this -> hash[0] = this -> hash[1] = nullptr;
        }
};

struct trie{
    node *root = new node(-1);
    void insert(string &s) const{
        node *tmp = root;
        for(auto c : s){
            if(tmp -> hash[c - '0'] == nullptr){
                tmp -> hash[c - '0'] = new node(c - '0');
            }
            tmp = tmp -> hash[c - '0'];
        }
    }
    int dfs(node *curnode, int zero, bool seen){
        seen |= (curnode -> data == 0);
        zero = (zero + (curnode -> data == 0)) % mod;
        int ans = 0;
        if(seen){
            ans = (ans + (zero - 1 + mod) % mod) % mod;
        }
        if(curnode -> hash[0]){
            ans = (ans + dfs(curnode -> hash[0], zero, seen)) % mod;
        }
        if(curnode -> hash[1]){
            ans = (ans + dfs(curnode -> hash[1], zero, seen)) % mod;
        }
        return ans;
    }
};


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n; trie bt{};
    for(int i = 1; i <= n; i++){
        string s;
        cin >> s;
        bt.insert(s);
    }
    cout << bt.dfs(bt.root, 0, false);
    return 0;
}
