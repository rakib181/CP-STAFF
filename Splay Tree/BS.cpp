#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// @author  heisenberg

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

#define long long long
typedef tree<pair<long, long>, null_type, greater<>, rb_tree_tag, tree_order_statistics_node_update> o_set;
const int inf = 1e9 + 7;
const int mod = 1e9 + 7;

struct node{
    int x{};
    node *l{}, *r{}, *p{};
    node()= default;
    explicit node(int _x){
        this -> x = _x;
        this -> p = nullptr;
        this -> l = nullptr;
        this -> r = nullptr;
    }
};

node *root;

void leftRotate(node *t){
    node *p = t -> r;
    node *q = p -> l;
    node *d = t -> p;
    if(d){
        if(d -> l == t){
            d -> l = p;
        }else{
            d -> r = p;
        }
    }
    if(q){
        q -> p = t;
    }
    p -> p = d;
    p -> l = t;
    t -> p = p;
    t -> r = q;
}

void rightRotate(node *t){
    node *p = t -> l;
    node *q = p -> r;
    node *d = t -> p;
    if(d){
        if(d -> l == t){
            d -> l = p;
        }else{
            d -> r = p;
        }
    }
    if(q){
        q -> p = t;
    }
    p -> p = d;
    p -> r = t;
    t -> p = p;
    t -> l = q;
}


void splay(node *t){
    while (true) {
        node *p = t -> p;
        if (!p)break;
        node *g = p -> p;
        //zig
        if (!g) {
            if (p -> l == t) {
                rightRotate(p);
            } else {
                leftRotate(p);
            }
            break;
        }
        if(g -> l == p){
            if(p -> l == t){
                //zig zig
                rightRotate(g);
                rightRotate(p);
            }else{
                //zig zag
                leftRotate(p);
                rightRotate(g);
            }
        }else{
            if(p -> r == t){
                //zig zig
                leftRotate(g);
                leftRotate(p);
            }else{
                //zig zag
                rightRotate(p);
                leftRotate(g);
            }
        }
    }
    root = t;
}

void insert(int x){
    if(!root){
        node *p = new node(x);
        root = p;
        return;
    }
    node *p = root;
    while (true){
        if(p -> x == x)break; // set
        if(x < p -> x){
            if(p -> l)p = p -> l;
            else{
                p -> l = new node(x);
                p -> l -> p = p;
                p = p -> l;
                break;
            }
        }else{
            if(p -> r)p = p -> r;
            else{
                p -> r = new node(x);
                p -> r -> p = p;
                p = p -> r;
                break;
            }
        }
    }
    splay(p);
}

node *find(int x){
    if(!root)return nullptr;
    node *p = root;
    while (true){
        if(p -> x == x)break;
        if(x < p -> x){
            if(p -> l){
                p = p -> l;
            }else{
                break;
            }
        }else{
            if(p -> r){
                p = p -> r;
            }else{
                break;
            }
        }
    }
    splay(p);
    if(p -> x == x)return p;
    return nullptr;
}


bool erase(int x){
    node *p = find(x);
    if(!p)return false;
    splay(p);
    node *t = p -> l;
    if(!t){
        root = p -> r;
        root -> p = nullptr;
        free(p);
        return true;
    }
    while (t -> r)t = t -> r;
    if(p -> r){
        t -> r = p -> r;
        p -> r -> p = t;
    }
    root = p -> l;
    root -> p = nullptr;
    free(p);
    return true;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        insert(x);
    }
    while (q--){
        int x;
        cin >> x;
        node *ans = find(x);
        if(ans)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
