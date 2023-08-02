#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 7e4 + 9;
struct node{
    node *dig[10]{};
    int cnt, idx;
    node(){
        for(auto &i : dig){
            i = nullptr;
        }
        this -> cnt = 0;
        this -> idx = -1;
    }
};
node *root;
void insert(string &s, int i){
     node *cur = root;
     for(auto x: s){
         int d = x - '0';
         if(cur -> dig[d] == nullptr){
             cur -> dig[d] = new node();
         }
         cur = cur -> dig[d];
         bool f = false;
         if(cur -> idx != i){
             f = true;
             cur -> idx = i;
         }
         if(f)cur -> cnt += 1;
     }
}

bool search(string &s){
    node *cur = root;
    for(auto x: s){
        int d = x - '0';
        cur = cur -> dig[d];
        if(cur -> cnt == 1)return true;
    }
    return false;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    root = new node();
    int n;
    cin >> n;
    vector<string> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < (int) a[i].size(); j++){
            string t;
            for(int k = j; k < (int) a[i].size(); k++){
                t += a[i][k];
                insert(t, i);
            }
        }
    }
    for(int i = 0; i < n; i++){
        string ans = "9999999999";
        for(int j = 0; j < (int) a[i].size(); j++){
            string t;
            for(int k = j; k < (int) a[i].size(); k++){
                t += a[i][k];
                if(search(t) and (int) t.size() <= (int) ans.size()){
                    ans = t;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
