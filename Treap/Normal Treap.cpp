#include<bits/stdc++.h>
using namespace std;

mt19937 mt(time(nullptr));
struct node{
    int x{}, y{};
    node *left{}, *right{};
    node()= default;
    explicit node(int data){
        this -> x = data;
        this -> y = (int) mt();
        this -> left = nullptr;
        this -> right = nullptr;
    }
};

node *merge(node *a, node *b){
     if(a == nullptr){
         return b;
     }
     if(b == nullptr){
         return a;
     }
     if(a -> y > b -> y){
         a -> right = merge(a -> right, b);
         return a;
     }else{
         b -> left = merge(a, b -> left);
         return b;
     }
}

pair<node*, node*> split(node *root, int x){
     if(root == nullptr){
         return {nullptr, nullptr};
     }
     if(root -> x <= x){
         pair<node*, node*> p = split(root -> right, x);
         root -> right = p.first;
         return {root, p.second};
     }else{
         pair<node*, node*> p = split(root -> left, x);
         root -> left = p.second;
         return {p.first, root};
     }
}

bool search(node *root, int x){
    if(root == nullptr){
        return false;
    }
    if(root -> x == x){
        return true;
    }
    if(root -> x < x){
        return search(root -> right, x);
    }else{
        return search(root -> left, x);
    }
}

node* add(node *root, int x){
    pair<node*, node*> p = split(root, x);
    p.first = merge(p.first, new node(x));
    root = merge(p.first, p.second);
    return root;
}

node* remove(node *root, int x){
    pair<node*, node*> p = split(root, x - 1);
    pair<node*, node*> g = split(p.second, x);
    root = merge(p.first, g.second);
    return root;
}

void print(node *root){
    if(root == nullptr)return;
    print(root -> left);
    cout << root -> x << '\n';
    print(root -> right);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    node *root = nullptr;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        root = add(root, x);
    }
    print(root);
    root = remove(root, 3);
    print(root);
    return 0;
}
