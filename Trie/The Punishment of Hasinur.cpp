#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct node{
    node * ch[26]{};
    string s;
    int mx, cnt{};
    node(){
       for(auto & i : ch){
           i = nullptr;
       }
       this -> mx = 0;
    }
};
node *root;

void insert(string &s, int c){
    node *tmp = root;
    for(auto x : s){
        int d = x - 'a';
        if(tmp -> ch[d] == nullptr){
            tmp -> ch[d] = new node();
        }
        tmp = tmp -> ch[d];
        if(c > tmp -> mx){
            tmp -> mx = c;
            tmp -> s = s;
        }else if(c == tmp -> mx and tmp -> s > s){
            tmp -> s = s;
        }
    }
}

string search(string &s){
    node *tmp = root;
    for(auto x: s){
        int d = x - 'a';
        if(tmp -> ch[d] == nullptr)return  "-1";
        tmp = tmp -> ch[d];
    }
    return tmp -> s;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, cs = 1;
    cin >> n;
    root = new node();
    map<string, int> mp;
    for(int i = 1; i <= n; i++){
        string s;
        cin >> s;
        mp[s] += 1;
        insert(s, mp[s]);
    }
    int q;
    cin >> q;
    while(q--){
        cout << "Case " << cs++ << ": ";
        string s;
        cin >> s;
        string ans = search(s);
        if(ans != "-1")cout << ans << ' ' << mp[ans] << '\n';
        else cout << ans << '\n';
    }
    return 0;
}
