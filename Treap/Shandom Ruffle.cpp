#include<bits/stdc++.h>
using namespace std;
#define long long long int

mt19937 mt(time(nullptr));

struct node{
    int x{}, y{}, sz{};
    node *left{}, *right{};
    node()= default;
    explicit node(int data){
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

void print(node *root){
    if(root == nullptr)return;
    print(root -> left);
    cout << root -> x << ' ';
    print(root -> right);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    node *root = nullptr;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        root = merge(root, new node(i));
    }
    for(int i = 1; i <= n; i++){
        int l, r;
        cin >> l >> r;
        if(l >= r)continue;
        int l_sz = r - l, r_sz = n - r + 1;
        int sz = min(l_sz, r_sz);
        pair<node *, node *> x = split(root, l - 1);
        pair<node *, node *> y = split(x.second, sz);
        pair<node*, node*> p = split(y.second, r - l - sz);
        pair<node *, node *> z = split(p.second, sz);
        root = merge(x.first, z.first);
        root = merge(root, p.first);
        root = merge(root, y.first);
        root = merge(root, z.second);
    }
    print(root);
    return 0;
}
