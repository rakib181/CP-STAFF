#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
const ll NO_OP = LLONG_MAX;
int a[N];
ll lazy[4 * N], prefix[N];
struct node{
    ll sum, w_sum;
}t[4 * N];

void merge(int n){
    t[n].sum = t[2 * n].sum + t[2 * n + 1].sum;
    t[n].w_sum = t[2 * n].w_sum + t[2 * n + 1].w_sum;
}

ll get(int l, int r){
    return prefix[r] -  prefix[l - 1];
}

void push(int n, int b, int e){
    if(lazy[n] == NO_OP)return;
    t[n].sum += (e - b + 1) * lazy[n];
    t[n].w_sum += (get(b, e) * lazy[n]);
    if(b != e){
        if(lazy[2 * n] != NO_OP) lazy[2 * n] += lazy[n];
        else lazy[2 * n] = lazy[n];
        if(lazy[2 * n + 1] != NO_OP) lazy[2 * n + 1] += lazy[n];
        else lazy[2 * n + 1] = lazy[n];
    }
    lazy[n] = NO_OP;
}

node f(node x, node y){
    return {x.sum + y.sum, x.w_sum + y.w_sum};
}

void build(int n, int b, int e){
    lazy[n] = NO_OP;
    if(b == e){
        t[n].sum = a[b];
        t[n].w_sum = b * a[b];
        return;
    }
    int m = (b + e) >> 1;
    build(2 * n, b, m);
    build(2 * n + 1, m + 1, e);
    merge(n);
}

void upd(int n, int b, int e, int l, int r, int v){
    push(n, b, e);
    if(b > r or e < l)return;
    if(b >= l and e <= r){
        lazy[n] = v;
        push(n, b, e);
        return;
    }
    int m = (b + e) >> 1;
    upd(2 * n, b, m, l, r, v);
    upd(2 * n + 1, m + 1, e, l, r, v);
    merge(n);
}

node query(int n, int b, int e, int l, int r){
    push(n, b, e);
    if(b > r or e < l)return {0, 0};
    if(b >= l and e <= r){
        return t[n];
    }
    int m = (b + e) >> 1;
    return f(query(2 * n, b, m, l, r), query(2 * n + 1, m + 1, e, l, r));
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q; prefix[0] = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        prefix[i] = prefix[i - 1] + i;
    }
    build(1, 1, n);
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int l, r, v;
            cin >> l >> r >> v;
            upd(1, 1, n, l, r, v);
        }else{
            int l, r;
            cin >> l >> r;
            node ans = query(1, 1, n, l, r);
            cout << ans.w_sum - ((l - 1) * ans.sum) << '\n';
        }
    }
    return 0;
}
