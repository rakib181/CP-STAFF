#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct node{
    int key, height;
    node *left, *right;
    explicit node(int k){
        this -> key = k;
        this -> height = 1;
        this -> left = nullptr;
        this -> right = nullptr;
    }
};
int height(node *v){
    if(v == nullptr)return 0;
    return v -> height;
}
int is_balance(node * v){
    if(v == nullptr) return 0;
    return height(v -> left) - height(v -> right);
}
node *left_rotate(node *z){
    node *x = z -> right;
    node *y = x -> left;
    x -> left = z;
    z -> right = y;
    z -> height = max(height(z -> left), height(z -> right)) + 1;
    x -> height = max(height(x -> left), height(x -> right)) + 1;
    return x;
}

node *right_rotate(node *z){
    node *x = z -> left;
    node *y = x -> right;
    x -> right = z;
    z -> left = y;
    z -> height = max(height(z -> left), height(z -> right)) + 1;
    x -> height = max(height(x -> left), height(x -> right)) + 1;
    return x;
}

node *insert(node* root, int key){
    if(root == nullptr){
        return new node(key);
    }
    if(root -> key > key){
        root -> left = insert(root -> left, key);
    }else{
        root -> right = insert(root -> right, key);
    }
    root -> height = 1 + max(height(root -> left), height(root -> right));
    int balance = is_balance(root);
    if(balance > 1 and root -> left -> key > key){
        return right_rotate(root);
    }
    if(balance < -1 and root -> right -> key < key){
        return left_rotate(root);
    }
    if(balance > 1 and root -> left -> key < key){
        root -> left = left_rotate(root -> left);
        return right_rotate(root);
    }
    if(balance < -1 and root -> right -> key > key){
        root -> right = right_rotate(root -> right);
        return left_rotate(root);
    }
    return root;
}

node *min_node(node * root){
    node *t = root;
    while(t -> left != nullptr){
        t = t -> left;
    }
    return t;
}

node *del(node *root, int key){
    if(root == nullptr)return root;
    if(root -> key > key){
        root -> left = del(root -> left, key);
    }else if(root -> key < key){
        root -> right = del(root -> right, key);
    }else{
        if(root -> left == nullptr or root -> right == nullptr){
            node *t = root -> left ? root -> left : root -> right;
            if(t == nullptr){
                t = root;
                root = nullptr;
            }else{
                *root = *t;
            }
            free(t);
        }else{
            node *t = min_node(root -> right);
            root -> key = t -> key;
            root -> right = del(root -> right, t -> key);
        }
    }
    root -> height = 1 + max(height(root -> left), height(root -> right));
    int balance = is_balance(root);
    if(balance > 1 and is_balance(root -> left) >= 0){
        return right_rotate(root);
    }
    if(balance < -1 and is_balance(root -> right) <= 0){
        return left_rotate(root);
    }
    if(balance > 1 and is_balance(root -> left) < 0){
        root -> left = left_rotate(root -> left);
        return right_rotate(root);
    }
    if(balance < -1 and is_balance(root -> right) > 0){
        root -> right = right_rotate(root -> right);
        return left_rotate(root);
    }
    return root;
}


void preorder(node *root){
    if(root == nullptr)return;
    cout << root -> key << ' ';
    preorder(root -> left);
    preorder(root -> right);
}

bool search(node *root, int key){
    if(root == nullptr)return false;
    if(root -> key == key)return true;
    bool f = false;
    if(root -> key > key){
        f |= search(root -> left, key);
    }else{
        f |= search(root -> right, key);
    }
    return f;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    node *root = nullptr;
    root = insert(root, 9);
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 0);
    root = insert(root, 6);
    root = insert(root, 11);
    root = insert(root, -1);
    root = insert(root, 1);
    root = insert(root, 2);
    printf("Preorder traversal of the constructed AVL "
           "tree is \n");
    preorder(root);

    root = del(root, 10);
    cout << root -> key << '\n';
    printf("\nPreorder traversal after deletion of 10 \n");
    preorder(root);
    cout << '\n';
    cout << search(root, -1) << ' ' << search(root, 50) << '\n';
    return 0;
}
