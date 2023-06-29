#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
struct node{
    ll val, lazy_set, lazy_add;
}t[4 * N];
void push(int n, int b, int e){
    int m = (b + e) >> 1;
    if(t[n].lazy_set != -1){
        t[2 * n].lazy_add = t[2 * n + 1].lazy_add = -1;
        t[2 * n].val = ((m - b + 1) * 1LL * t[n].lazy_set);
        t[2 * n + 1].val = ((e - m) * 1LL * t[n].lazy_set);
        t[2 * n].lazy_set = t[2 * n + 1].lazy_set = t[n].lazy_set;
        t[n].lazy_set = -1;
    }
    if(t[n].lazy_add != -1){
        if(t[2 * n].val != -1) t[2 * n].val += ((m - b + 1) * 1LL * t[n].lazy_add);
        else t[2 * n].val = ((m - b + 1) * 1LL * t[n].lazy_add);
        if(t[2 * n + 1].val != -1)t[2 * n + 1].val += ((e - m) * 1LL * t[n].lazy_add);
        else t[2 * n + 1].val = ((e - m) * 1LL * t[n].lazy_add);
        if(t[2 * n].lazy_add != -1)t[2 * n].lazy_add += t[n].lazy_add;
        else t[2 * n].lazy_add = t[n].lazy_add;
        if(t[2 * n + 1].lazy_add != -1)t[2 * n + 1].lazy_add += t[n].lazy_add;
        else t[2 * n + 1].lazy_add = t[n].lazy_add;
        t[n].lazy_add = -1;
    }
}
void upd(int n, int b, int e, int l, int r, int val, bool set, bool add){
    push(n, b, e);
    if(b > r or e < l)return;
    if(b >= l and e <= r){
        if(set){
            t[n].val = ((e - b + 1) * 1LL * val);
            t[n].lazy_set = val;
            t[n].lazy_add = -1;
            push(n, b, e);
            return;
        }
        if(add){
            t[n].val += ((e - b + 1) * 1LL * val);
            if(t[n].lazy_add != -1) t[n].lazy_add += val;
            else t[n].lazy_add = val;
            t[n].lazy_set = -1;
            push(n, b, e);
            return;
        }
    }
    int m = (b + e) >> 1;
    upd(2 * n, b, m, l, r, val, set, add);
    upd(2 * n + 1, m + 1, e, l, r, val, set, add);
    t[n].val = t[2 * n].val + t[2 * n + 1].val;
}

ll query(int n, int b, int e, int l, int r){
    push(n, b, e);
    if(b > r or e < l)return 0;
    if(b >= l and e <= r){
        return t[n].val;
    }
    int m = (b + e) >> 1;
    return query(2 * n, b, m, l, r) + query(2 * n + 1, m + 1, e, l, r);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= 4 * n; i++){
        t[i] = {0, -1, -1};
    }
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int l, r, v;
            cin >> l >> r >> v;
            l += 1;
            upd(1, 1, n, l, r, v, true, false);
        }else if(type == 2){
            int l, r, v;
            cin >> l >> r >> v;
            l += 1;
            upd(1, 1, n, l, r, v, false, true);
        }else{
            int l, r;
            cin >> l >> r;
            l += 1;
            cout << query(1, 1, n, l, r) << '\n';
        }
    }
    return 0;
}
