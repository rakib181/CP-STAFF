#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct node{
    node *zero, *one;
    node(){
        this -> zero = nullptr;
        this -> one = nullptr;
    }
};

node *root = new node();
void insert(int v){
    node *tmp = root;
    for(int i = 31; i >= 0; i--){
        if(v & (1 << i)){
            if(tmp -> one == nullptr){
                tmp -> one = new node();
            }
            tmp = tmp -> one;
        }else{
            if(tmp -> zero == nullptr){
                tmp -> zero = new node();
            }
            tmp = tmp -> zero;
        }
    }
}

int getMax(int v){
    node *cur = root;
    for(int i = 31; i >= 0; i--){
        if(v & (1 << i)){
            if(cur -> zero != nullptr){
                cur = cur -> zero;
            }else{
                cur = cur -> one;
                v &= ~(1 << i);
            }
        }else{
            if(cur -> one != nullptr){
                cur = cur -> one;
                v |= (1 << i);
            }else{
                cur = cur -> zero;
            }
        }
    }
    return v;
}

int getMin(int v){
    node *cur = root;
    for(int i = 31; i >= 0; i--){
        if(v & (1 << i)){
            if(cur -> one != nullptr){
                v &= ~(1 << i);
                cur = cur -> one;
            }else{
                cur = cur -> zero;
            }
        }else{
            if(cur -> zero != nullptr){
                cur = cur -> zero;
            }else{
                cur = cur -> one;
                v |= (1 << i);
            }
        }
    }
    return v;
}

void del(node *root){
    if(root -> one){
        del(root -> one);
    }
    if(root -> zero){
        del(root -> zero);
    }
    delete(root);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, cs = 1;
    cin >> t;
    while(t--){
        cout << "Case " << cs++ << ": ";
        int n; root = new node();
        cin >> n;
        int a = 0, mn = INT_MAX, mx = INT_MIN;
        insert(a);
        for(int i = 0; i < n; i++){
            int v;
            cin >> v;
            a ^= v;
            mn = min(mn, getMin(a));
            mx = max(mx, getMax(a));
            insert(a);
        }
        cout << mx << ' ' << mn << '\n';
        del(root);
    }
    return 0;
}
