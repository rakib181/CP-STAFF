#include<bits/stdc++.h>
using namespace std;
#define long long long int

mt19937 mt(time(nullptr));

struct node{
    char x{}; int y{}, sz{};
    node *left{}, *right{};
    node()= default;
    explicit node(char data){
        this -> x = data;
        this -> y = (int) mt();
        this -> sz = 1;
        this -> left = nullptr;
        this -> right = nullptr;
    }
};

int size(node *root){
    return (root ? root -> sz : 0);
}

node *merge(node *a, node *b){
    if(a == nullptr){
        return b;
    }
    if(b == nullptr){
        return a;
    }
    if(a -> y > b -> y){
        node *p = merge(a -> right, b);
        a -> right = p;
        a -> sz = 1 + size(a -> left) + size(a -> right);
        return a;
    }else{
        node *p = merge(a, b -> left);
        b -> left = p;
        b -> sz = 1 + size(b -> left) + size(b -> right);
        return b;
    }
}

pair<node*, node*> split(node *root, int k){
    if(root == nullptr){
        return {nullptr, nullptr};
    }
    if(size(root -> left) < k){
        pair<node*, node*> p = split(root -> right, k - size(root -> left) - 1);
        root -> right = p.first;
        root -> sz = 1 + size(root -> left) + size(root -> right);
        return {root, p.second};
    }else{
        pair<node*, node*> p = split(root -> left, k);
        root -> left = p.second;
        root -> sz = 1 + size(root -> left) + size(root -> right);
        return {p.first, root};
    }
}

node* add(node *root, char x, int ind){
    pair<node*, node*> p = split(root, ind - 1);
    p.first = merge(p.first, new node(x));
    root = merge(p.first, p.second);
    return root;
}

node* remove(node *root, int ind){
    pair<node*, node*> p = split(root, ind - 1);
    pair<node*, node*> g = split(p.second, 1);
    root = merge(p.first, g.second);
    return root;
}

void print(node *root){
    if(root == nullptr)return;
    print(root -> left);
    cout << root -> x;
    print(root -> right);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    node *root = nullptr;
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    for(auto x : s){
        root = merge(root, new node(x));
    }
    while(q--){
        int l, r;
        cin >> l >> r;
        pair<node*, node*> p = split(root, l - 1);
        pair<node*, node*> nx = split(p.second, (r - l + 1));
        root = merge(p.first, nx.second);
        root = merge(root, nx.first);
    }
    print(root);
    return 0;
}
