#include<bits/stdc++.h>
using namespace std;
#define int long long int

const int N = 1e6 + 9, P = 131, MOD = 998244353;
int a[N], POW[N], INV_POW[N], t[4 * N];

int bin(int x, int y){
    int ans = 1;
    while (y){
        if(y & 1) ans = ans * x % MOD;
        x = x * x % MOD;
        y >>= 1;
    }
    return ans;
}

void cal(){
    POW[1] = 1;
    for(int i = 2; i < N; i++){
        POW[i] = (((P % MOD) * (POW[i - 1] % MOD)) % MOD) % MOD;
    }
    int PP = bin(P, MOD - 2);
    INV_POW[1] = 1;
    for(int i = 2; i < N; i++){
        INV_POW[i] = (((PP % MOD) * (INV_POW[i - 1] % MOD)) % MOD) % MOD;
    }
}


void build(int node, int s, int e) {
    if(s == e) {
        t[node] = (((a[s] % MOD) * (POW[s] % MOD)) % MOD) % MOD;
        return;
    }
    int mid = (s + e) >> 1;
    int l = node << 1, r = l | 1;
    build(l, s, mid);
    build(r, mid + 1, e);
    t[node] = (((t[l] % MOD) + (t[r] % MOD)) % MOD) % MOD;
}

void upd(int node, int s, int e, int idx, int val){
    if(s > idx or e < idx)return;
    if(s == idx && e == idx) {
        t[node] = (((val % MOD) * (POW[s] % MOD)) % MOD) % MOD;
        return;
    }
    int mid = (s + e) >> 1;
    int l = node << 1, r = l | 1;
    upd(l, s, mid, idx, val);
    upd(r, mid + 1, e, idx, val);
    t[node] = (((t[l] % MOD) + (t[r] % MOD)) % MOD) % MOD;
}

int query(int node, int s, int e, int l, int r) {
    if(s > r or e < l)return 0;
    if(s >= l and r >= e)return t[node];
    int mid = (s + e) >> 1;
    int i = node << 1, j = i | 1;
    return (((query(i, s, mid, l, r) % MOD) + (query(j, mid + 1, e , l , r) % MOD)) % MOD) % MOD;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cal();
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    build(1, 1, n);
    int hash = 0;
    for(int i = 1; i <= m; i++){
        int x;
        cin >> x;
        hash = (((hash % MOD) + ((x * POW[i]) % MOD)) % MOD) % MOD;
    }
    int q;
    cin >> q;
    while (q--){
        int type;
        cin >> type;
        if(type == 1){
            int i, v;
            cin >> i >> v;
            upd(1, 1, n, i, v);
        }else{
            int l, r;
            cin >> l >> r;
            int x = (query(1, 1, n, l, r) * INV_POW[l]) % MOD;
            if(x == hash)cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }
    }
    return 0;
}
