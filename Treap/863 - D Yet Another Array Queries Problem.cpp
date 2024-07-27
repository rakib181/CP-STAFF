#include<bits/stdc++.h>
using namespace std;
#define long long long int

mt19937 mt(time(nullptr));

struct node{
    int x{}, y{}, sz{};
    node *left{}, *right{};
    bool rev{};
    node()= default;
    explicit node(int data){
        this -> x = data;
        this -> y = (int) mt();
        this -> sz = 1;
        this -> rev = false;
        this -> left = nullptr;
        this -> right = nullptr;
    }
};

int size(node *root){
    return (root ? root -> sz : 0);
}

void push(node *root){
    if(root == nullptr)return;
    if(root -> rev){
        swap(root -> left, root -> right);
        if(root -> left)root -> left -> rev ^= true;
        if(root -> right) root -> right -> rev ^= true;
        root -> rev = false;
    }
}

node *merge(node *a, node *b){
    if(a == nullptr){
        return b;
    }
    if(b == nullptr){
        return a;
    }
    push(a);
    push(b);
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
    push(root);
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
    push(root);
    print(root -> left);
    cout << root -> x << ' ';
    print(root -> right);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    node *root = nullptr;
    int n, q, m;
    cin >> n >> q >> m;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        root = merge(root, new node(x));
    }
    while(q--){
        int type;
        cin >> type;
        int l, r;
        cin >> l >> r;
        if(type == 1){
            pair<node*, node*> x = split(root, l - 1);
            pair<node*, node*> y = split(x.second, r - l);
            pair<node*, node*> z = split(y.second, 1);
            root = merge(x.first, z.first);
            root = merge(root, y.first);
            root = merge(root, z.second);
        }else{
            pair<node*, node*> p = split(root, l - 1);
            pair<node*, node*> nx = split(p.second, (r - l + 1));
            nx.first -> rev ^= true;
            root = merge(p.first, nx.first);
            root = merge(root, nx.second);
        }
    }
    for(int i = 1; i <= m; i++){
        int x;
        cin >> x;
        pair<node*, node*> p = split(root, x - 1);
        pair<node*, node*> v = split(p.second, 1);
        cout << v.first -> x << ' ';
        root = merge(p.first, v.first);
        root = merge(root, v.second);
    }
    return 0;
}
