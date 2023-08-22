#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct node{
    node *zero, *one;
    int idx, val;
    node(){
        this -> zero = nullptr;
        this -> one = nullptr;
        this -> val = -1;
        this -> idx = -1;
    }
};
int n, k;
node *root = new node();
void insert(int v, int id){
    node *tmp = root;
    for(int i = k - 1; i >= 0; i--){
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
    tmp -> idx = id;
    tmp -> val = v;
}

node *query(int x){
    node *t = root;
    for(int i = k - 1; i >= 0; i--){
        int bit = ((x >> i) & 1);
        if(bit){
            if(t -> one){
                t = t -> one;
            }else t = t -> zero;
        }else{
            if(t -> zero){
                t = t -> zero;
            }else t = t -> one;
        }
    }
    return t;
}

void del(node *r){
    if(r -> one){
        del(r-> one);
    }
    if(r -> zero){
        del(r -> zero);
    }
    delete(r);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        int a[n + 1];
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        root = new node();
        int ans = INT_MAX, idx1 = 0, idx2 = 0;
        insert(a[1], 1);
        for(int i = 2; i <= n; i++){
            auto need= query(a[i]);
            int val = (need -> val ^ a[i]);
            if(val < ans){
                ans = val;
                idx1 = need -> idx;
                idx2 = i;
            }
            insert(a[i], i);
        }
        int build = 0;
        for(int i = k - 1; i >= 0; i--){
            int v1 = ((a[idx1] >> i) & 1), v2 = ((a[idx2] >> i) & 1);
            if(v1 == 0 and v2 == 0){
                build |= (1 << i);
            }
        }
        cout << idx1 << ' ' << idx2  << ' ' << build << '\n';
        del(root);
    }
    return 0;
}
