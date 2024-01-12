#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 9, mod = 998244353;
int n, a[N];
int t[4 * N];
pair<int, int> lazy[4 * N];

int bin(int x, int y){
    int ans = 1;
    while(y){
        if(y & 1) ans = 1LL * ans * x % mod;
        x = 1LL * x * x % mod;
        y >>= 1;
    }
    return ans;
}

void build(int node, int b, int e){
    lazy[node] = {1, 0};
    if(b == e){
        t[node] = a[b];
        return;
    }
    int m = (b + e) >> 1;
    build(2 * node, b, m);
    build(2 * node + 1, m + 1, e);
    t[node] =  (t[2 * node] + t[2 * node + 1]) % mod;
}

void push(int node, int b, int e){
    int val = lazy[node].first * t[node] % mod;
    int x = (e - b + 1) * lazy[node].second % mod;
    t[node] = (val + x) % mod;
    if(b != e){
        lazy[2 * node].first *= lazy[node].first;
        lazy[2 * node].first %= mod;
        lazy[2 * node].second *= lazy[node].first;
        lazy[2 * node].second %= mod;
        lazy[2 * node].second += lazy[node].second;
        lazy[2 * node].second %= mod;
        lazy[2 * node + 1].first *= lazy[node].first;
        lazy[2 * node + 1].first %= mod;
        lazy[2 * node + 1].second *= lazy[node].first;
        lazy[2 * node + 1].second %= mod;
        lazy[2 * node + 1].second += lazy[node].second;
        lazy[2 * node + 1].second %= mod;
    }
    lazy[node] = make_pair(1, 0);
}

void upd(int node, int b, int e, int l, int r, int B, int C){
    push(node, b, e);
    if(b > r or e < l)return;
    if(b >= l and e <= r){
        lazy[node].first *= B;
        lazy[node].first %= mod;
        lazy[node].second += C;
        lazy[node].second %= mod;
        push(node, b, e);
        return;
    }
    int m = (b + e) >> 1;
    upd(2 * node, b, m, l, r, B, C);
    upd(2 * node + 1, m + 1, e, l, r, B, C);
    t[node] = (t[2 * node] + t[2 * node + 1]) % mod;
}

int query(int node, int b, int e, int l, int r){
    push(node, b, e);
    if(b > r or e < l)return 0;
    if(b >= l and e <= r){
        return t[node];
    }
    int m = (b + e) >> 1;
    int ans = (query(2 * node, b, m, l, r) + query(2 * node + 1, m + 1, e, l, r)) % mod;
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < 4 * N; i++){
        t[i] = 0;
        lazy[i] = make_pair(1, 0);
    }
    build(1, 1, n);
    while(q--){
        int l, r, x;
        cin >> l >> r >> x;
        int b = (r - l) * bin((r - l + 1), mod - 2) % mod;
        int c = x  * bin(r - l + 1, mod - 2) % mod;
        upd(1, 1, n, l, r, b, c);
    }
    for(int i = 1; i <= n; i++){
        cout << query(1, 1, n, i, i) << ' ';
    }
    return 0;
}
