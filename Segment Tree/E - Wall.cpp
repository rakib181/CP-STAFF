#include<bits/stdc++.h>
using namespace std;

#define long long long
const int inf = 1e9 + 7;

struct item{
    int value, op, l, r;
    item() : value(0), op(-1), l(-1), r(inf) {};
};

const int N = 3e6 + 9;
vector<item> t(4 * N);

void fa(int node, int v){
    t[node].value = max(t[node].value, v);
    t[node].l = max(t[node].l, v);
    t[node].r = max(t[node].r, v);
    t[node].op = 0;
}

void fr(int node, int v){
    t[node].value = min(t[node].value, v);
    t[node].l = min(t[node].l, v);
    t[node].r = min(t[node].r, v);
    t[node].op = 1;
}

void push(int node){
     if(t[node].op == 0){
         if(t[node].l != -1) {
             fa(2 * node, t[node].l);
             fa(2 * node + 1, t[node].l);
         }
         if(t[node].r != inf){
             fr(2 * node, t[node].r);
             fr(2 * node + 1, t[node].r);
         }
     }
     if(t[node].op == 1){
         if(t[node].l != -1) {
             fa(2 * node, t[node].l);
             fa(2 * node + 1, t[node].l);
         }
         if(t[node].r != inf){
             fr(2 * node, t[node].r);
             fr(2 * node + 1, t[node].r);
         }
     }
     t[node].l = -1, t[node].r = inf;
}

void upd(int node, int b, int e, int l, int r, int op, int v){
    push(node);
    if(b > r or e < l)return;
    if(b >= l and e <= r){
        if(op == 0){
            fa(node, v);
        }else{
            fr(node, v);
        }
        push(node);
        return;
    }
    int m = (b + e) >> 1;
    upd(2 * node, b, m, l, r, op, v);
    upd(2 * node + 1, m + 1, e, l, r, op, v);
}

vector<int> ans(N);
void query(int node, int b, int e, int l, int r){
    push(node);
    if(b == e){
       ans[b] = t[node].value;
        return;
    }
    int m = (b + e) >> 1;
    query(2 * node, b, m, l, r);
    query(2 * node + 1, m + 1, e, l, r);
}



signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int l, r, h;
            cin >> l >> r >> h;
            l++, r++;
            upd(1, 1, n, l, r, 0, h);
        }else{
            int l, r, h;
            cin >> l >> r >> h;
            l++, r++;
            upd(1, 1, n, l, r, 1, h);
        }
    }
    query(1, 1, n, 1, n);
    for(int i = 1; i <= n; i++){
        cout << ans[i] << '\n';
    }
    return 0;
}
