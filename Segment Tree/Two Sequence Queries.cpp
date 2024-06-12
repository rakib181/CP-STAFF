#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 3e5 + 9, mod = 998244353;
struct item{
    int sa, sb, s, la, lb;
}t[4 * N];
int n, q, A[N], B[N];

item merge(item x, item y){
    item ans{};
    ans.sa = 1LL * (1LL * x.sa + y.sa) % mod;
    ans.sb = 1LL * (1LL * x.sb + y.sb) % mod;
    ans.s = 1LL * (1LL * x.s + y.s) % mod;
    return ans;
}

void push(int node, int b, int e){
     int len = e - b + 1;
     if(t[node].la){
         t[2 * node].la = 1LL * (1LL * t[2 * node].la + t[node].la) % mod;
         t[2 * node + 1].la = 1LL * (1LL * t[2 * node + 1].la + t[node].la) % mod;
         t[2 * node].s = 1LL * (1LL * t[2 * node].s + 1LL * t[2 * node].sb * t[node].la % mod) % mod;
         t[2 * node + 1].s = 1LL * (1LL * t[2 * node + 1].s + 1LL * t[2 * node + 1].sb * t[node].la % mod) % mod;
         t[2 * node].sa = 1LL * (1LL * t[2 * node].sa + 1LL * (len - (len >> 1)) * t[node].la % mod) % mod;
         t[2 * node + 1].sa = 1LL * (1LL * t[2 * node + 1].sa + 1LL * (len >> 1) * t[node].la % mod) % mod;
         t[node].la = 0 ;
     }
     if(t[node].lb){
         t[2 * node].lb = 1LL * (1LL * t[2 * node].lb + t[node].lb) % mod;
         t[2 * node + 1].lb = 1LL * (1LL * t[2 * node + 1].lb + t[node].lb) % mod;
         t[2 * node].s = 1LL * (1LL * t[2 * node].s + 1LL * t[2 * node].sa * t[node].lb % mod) % mod;
         t[2 * node + 1].s = 1LL * (1LL * t[2 * node + 1].s + 1LL* t[2 * node + 1].sa * t[node].lb % mod) % mod;
         t[2 * node].sb = 1LL * (1LL * t[2 * node].sb + 1LL * (len - (len >> 1)) * t[node].lb % mod) % mod;
         t[2 * node + 1].sb = 1LL * (1LL * t[2 * node + 1].sb + 1LL * (len >> 1) * t[node].lb % mod) % mod;
         t[node].lb = 0 ;
     }
}

void build(int node, int b, int e){
    t[node] = {0, 0, 0, 0, 0};
    if(b == e){
        t[node] = {A[b], B[b], int(1LL * A[b] * B[b] % mod), 0, 0};
        return;
    }
    int m = (b + e) >> 1;
    build(2 * node, b, m);
    build(2 * node + 1, m + 1, e);
    t[node] = merge(t[2 * node], t[2 * node + 1]);
}

void upd(int node, int b, int e, int l, int r, int id, int x){
    push(node, b, e);
    if(b > r or e < l)return;
    if(b >= l and e <= r){
        if(id == 1){
            t[node].sa = 1LL * (1LL * t[node].sa + 1LL * x * (e - b + 1) % mod) % mod;
            t[node].la = 1LL * (1LL * t[node].la + x) % mod;
            t[node].s = 1LL * (1LL * t[node].s + 1LL * x * t[node].sb % mod) % mod;
        }else{
            t[node].sb = 1LL * (1LL * t[node].sb + 1LL * x * (e - b + 1) % mod) % mod;
            t[node].lb = 1LL * (1LL * t[node].lb + x) % mod;
            t[node].s = 1LL * (1LL * t[node].s + 1LL * x * t[node].sa % mod) % mod;
        }
        push(node, b, e);
        return;
    }
    int m = (b + e) >> 1;
    upd(2 * node, b, m, l, r, id, x);
    upd(2 * node + 1, m + 1, e, l, r, id, x);
    t[node] = merge(t[2 * node], t[2 * node + 1]);
}


int query(int node, int b, int e, int l, int r){
    push(node, b, e);
    if(b > r or e < l)return 0;
    if(b >= l and e <= r)return t[node].s;
    int m = (b + e) >> 1;
    return 1LL * (1LL * query(2 * node, b, m, l, r) + query(2 * node + 1, m + 1, e, l, r)) % mod;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    for(int i = 1; i <= n; i++)cin >> A[i];
    for(int i = 1; i <= n; i++)cin >> B[i];
    build(1, 1, n);
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int l, r, x;
            cin >> l >> r >> x;
            upd(1, 1, n, l, r, 1, x);
        }else if(type == 2){
            int l, r, x;
            cin >> l >> r >> x;
            upd(1, 1, n, l, r, 2, x);
        }else{
            int l, r;
            cin >> l >> r;
            auto ans = query(1, 1, n, l, r);
            cout << ans << '\n';
        }
    }
    return 0;
}
