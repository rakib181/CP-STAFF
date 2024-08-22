#include<bits/stdc++.h>
using namespace std;
#define long long long int

const int N = (1 << 20);
vector<bool> vis(N);

struct node{
    node *bit[2]{};
    node(){
        this -> bit[0] = nullptr;
        this -> bit[1] = nullptr;
    }
};
node *root;

void insert(int x){
    node *t = root;
    for(int i = 20; i >= 0; i--){
        int b = (x >> i) & 1;
        if(t -> bit[b] == nullptr){
            t -> bit[b] = new node();
        }
        t = t -> bit[b];
    }
}

int get(int x){
    node *t = root;
    int ans = 0;
    for(int i = 20; i >= 0; i--){
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

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    root = new node();
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        vis[x] = true;
    }
    for(int i = 0; i < N; i++){
        if(!vis[i])insert(i);
    }
    int val = 0;
    while(q--){
        int x;
        cin >> x;
        val ^= x;
        cout << get(val) << '\n';
    }
    return 0;
}
