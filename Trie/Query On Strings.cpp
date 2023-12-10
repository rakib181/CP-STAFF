#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct node{
    node *ch[26]{};
    int cnt;
    node(){
        for(int i = 0; i < 26; i++){
            ch[i] = nullptr;
            cnt = 0;
        }
    }
};

node *root = new node();

void add(string &s){
    node *tmp = root;
    for(auto x: s){
        if(tmp -> ch[x - 'a'] == nullptr){
            tmp -> ch[x - 'a'] = new node();
        }
        tmp -> cnt += 1;
        tmp = tmp -> ch[x - 'a'];
    }
    tmp -> cnt += 1;
}


void del(string &s){
    node *tmp = root;
    for(auto x : s){
        tmp -> cnt -= 1;
        tmp = tmp -> ch[x - 'a'];
    }
    tmp -> cnt -= 1;
}

bool search(node *tmp, int k, int l){
    if(!tmp or tmp -> cnt < k)return false;
    priority_queue<pair<int, node*>> pq;
    pq.emplace(0, tmp);
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        if(it.first >= l)return true;
        for(auto x : it.second -> ch){
            if(x and x -> cnt >= k){
                pq.emplace(it.first + 1, x);
            }
        }
    }
    return false;
}




signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> q;
    vector<string> op(q + 1);
    for(int i = 1; i <= q; i++){
        int type;
        cin >> type;
        if(type == 1){
            string s;
            cin >> s;
            reverse(s.begin(), s.end());
            add(s);
            op[i] = s;
        }else if(type == 2){
            int k, l;
            cin >> k >> l;
            bool found = search(root, k, l);
            cout << (found ? "YES\n" : "NO\n");
        }else{
            int x;
            cin >> x;
            if(!op[x].empty()) del(op[x]), op[x] = "";
        }
    }
    return 0;
}
