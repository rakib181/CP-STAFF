#include<bits/stdc++.h>
using namespace std;

#define long long long

struct item{
    char first{}, second{}, second_lst{}, lst{};
    int lazy{};
    bool good{};
    item() : first(0), second(0), second_lst(0), lst(0), lazy(0), good(true) {};
};

const int N = 2e5 + 9;
vector<item> t(4 * N);
string s;

item merge(item x, item y){
    if(x.first == 0)return y;
    if(y.first == 0)return x;
    item ans{};
    ans.first = x.first;
    ans.second = x.second ? x.second : y.first;
    ans.second_lst = y.second_lst ? y.second_lst : x.lst;
    ans.lst = y.lst;
    ans.good = x.good and y.good and (x.lst != y.first) and (x.second_lst == 0 || (x.second_lst != y.first)) and
               (y.second == 0 || (y.second != x.lst));
    return ans;
}


void push(int node, int b, int e){
    if(t[node].lazy){
        t[node].first = ((t[node].first - 'a' + t[node].lazy) % 26 + 'a');
        t[node].second = (t[node].second ? char((t[node].second - 'a' + t[node].lazy) % 26 + 'a') : 0);
        t[node].second_lst = (t[node].second_lst ? ((t[node].second_lst - 'a' + t[node].lazy) % 26 + 'a') : 0);
        t[node].lst = ((t[node].lst - 'a' + t[node].lazy) % 26 + 'a');
        if(b != e){
            t[2 * node].lazy += t[node].lazy;
            t[2 * node].lazy %= 26;
            t[2 * node + 1].lazy += t[node].lazy;
            t[2 * node + 1].lazy %= 26;
        }
        t[node].lazy = 0;
    }
}

void build(int node, int b, int e){
    if(b == e){
        t[node] = {};
        t[node].first = s[b];
        t[node].lst = s[b];
        t[node].good = true;
        return;
    }
    int m = (b + e) >> 1;
    build(2 * node, b, m);
    build(2 * node + 1, m + 1, e);
    t[node] = merge(t[2 * node], t[2 * node + 1]);
}

void upd(int node, int b, int e, int l, int r, int v){
    push(node, b, e);
    if(b > r or e < l)return;
    if(b >= l and e <= r){
        t[node].lazy = v;
        push(node, b, e);
        return;
    }
    int m = (b + e) >> 1;
    upd(2 * node, b, m, l, r, v);
    upd(2 * node + 1, m + 1, e, l, r, v);
    t[node] = merge(t[2 * node], t[2 * node + 1]);
}

item query(int node, int b, int e, int l, int r){
    push(node, b, e);
    if(b > r or e < l)return {};
    if(b >= l and e <= r){
        return t[node];
    }
    int m = (b + e) >> 1;
    return merge(query(2 * node, b, m, l, r), query(2 * node + 1, m + 1, e, l, r));
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--) {
       int n, q;
       cin >> n >> q;
       cin >> s;
       s = '$' + s;
       for(int i = 1; i <= 4 * n; i++){
          t[i] = {};
       }
       build(1, 1, n);
       while(q--){
           int type;
           cin >> type;
           if(type == 1){
               int l, r, x;
               cin >> l >> r >> x;
               upd(1, 1, n, l, r, x);
           }else{
               int l, r;
               cin >> l >> r;
               if(query(1, 1, n, l, r).good)cout << "YES\n";
               else cout << "NO\n";
           }
       }
    }
    return 0;
}
