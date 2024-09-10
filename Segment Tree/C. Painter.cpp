#include<bits/stdc++.h>
using namespace std;

#define long long long
struct item{
    int fst, lst, seg, cnt, lazy;
    item() : fst(0), lst(0), seg(0), cnt(0), lazy(-1) {};
};
const int N = 1e6 + 9;
vector<item> t(4 * N);

void push(int node, int b, int e){
    if(t[node].lazy != -1){
        if(t[node].lazy == 0){
            t[node].fst = 0;
            t[node].lst = 0;
            t[node].seg = 0;
            t[node].cnt = 0;
        }else{
            t[node].fst = 1;
            t[node].lst = 1;
            t[node].seg = 1;
            t[node].cnt = (e - b + 1);
        }
        if(b != e){
            t[2 * node].lazy = t[node].lazy;
            t[2 * node + 1].lazy = t[node].lazy;
        }
    }
    t[node].lazy = -1;
}

item merge(item x, item y){
    item ans{};
    ans.fst = x.fst;
    ans.lst = y.lst;
    ans.seg = x.seg + y.seg;
    if(x.lst == 1 and y.fst == 1){
        ans.seg--;
    }
    ans.cnt = x.cnt + y.cnt;
    return ans;
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


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> q;
    while(q--){
        char c; int l, r;
        cin >> c >> l >> r;
        l += 5e5;
        r += l - 1;
        if(c == 'W'){
           upd(1, 0, N, l, r, 0);
        }else{
           upd(1, 0, N, l, r, 1);
        }
        item ans = query(1, 0, N, 0, N);
        cout << ans.seg << ' ' << ans.cnt << '\n';
    }
    return 0;
}
