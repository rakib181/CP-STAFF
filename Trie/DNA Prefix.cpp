#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct node{
    node *f[4]{};
    int cnt;
    node(){
       this -> cnt = 0;
       for(auto i: f){
           i = nullptr;
       }
    }
};
node *root;

void insert(string &s){
    node *cur = root;
    for(auto c: s){
        int x = 0;
        if(c == 'C')x = 1;
        else if(c == 'G')x = 2;
        else if(c == 'T')x = 3;
        if(cur -> f[x] == nullptr){
            cur -> f[x] = new node();
        }
        cur = cur -> f[x];
        cur->cnt += 1;
    }
}

int search(node *cur, int lvl){
    int ans = cur -> cnt * lvl;
    for(auto i : cur -> f){
        if(i != nullptr){
            ans = max(ans, search(i, lvl + 1));
        }
    }
    return ans;
}

void del(node *r){
    for(auto & i : r -> f){
        if(i != nullptr){
            del(i);
        }
    }
    delete(r);
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
        for(int i = 1; i <= n; i++){
            string s;
            cin >> s;
            insert(s);
        }
        cout << search(root, 0) << '\n';
        del(root);
    }
    return 0;
}
