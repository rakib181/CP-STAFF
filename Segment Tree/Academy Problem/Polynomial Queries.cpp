#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
int n, q, a[N];
ll t[4 * N];

struct item{
    ll first; int cnt;
}lazy[4 * N];

ll gauss(ll first, int len, int cnt){
    return first * len + 1LL * cnt * len * (len - 1) / 2;
}

void push(int node, int b, int e){
    if(lazy[node].first == 0)return;
    int m = (b + e) >> 1;
    t[node] += gauss(lazy[node].first, e - b + 1, lazy[node].cnt);
    if(b != e){
        lazy[2 * node].first += lazy[node].first;
        lazy[2 * node].cnt += lazy[node].cnt;
        lazy[2 * node + 1].first += lazy[node].first + 1LL * (m - b + 1) * lazy[node].cnt;
        lazy[2 * node + 1].cnt += lazy[node].cnt;
    }
    lazy[node] = {0, 0};
}

void build(int node, int b, int e){
    if(b == e){
        t[node] = a[b];
        return;
    }
    int m = (b + e) >> 1;
    build(2 * node, b, m);
    build(2 * node + 1, m + 1, e);
    t[node] = t[2 * node] + t[2 * node + 1];
}

void upd(int node, int b, int e, int l, int r){
    push(node, b, e);
    if(b > r or e < l)return;
    if(b >= l and e <= r){
        lazy[node].first = (b - l + 1);
        lazy[node].cnt += 1;
        push(node, b, e);
        return;
    }
    int m = (b + e) >> 1;
    upd(2 * node, b, m, l, r);
    upd(2 * node + 1, m + 1, e, l, r);
    t[node] = t[2 * node] + t[2 * node + 1];
}

ll query(int node, int b, int e, int l, int r){
    push(node, b, e);
    if(b > r or e < l)return 0;
    if(b >= l and e <= r){
        return t[node];
    }
    int m = (b + e) >> 1;
    return query(2 * node, b, m, l, r) + query(2 * node + 1, m + 1, e, l, r);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    build(1, 1, n);
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int l, r;
            cin >> l >> r;
            upd(1, 1, n, l, r);
        }else{
            int l, r;
            cin >> l >> r;
            cout << query(1, 1, n, l, r) << '\n';
        }
    }
    return 0;
}
