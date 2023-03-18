#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 1e5 + 9, MOD = 1e9 + 7;
int A[N];    int n, q;
int seg[4 * N];
int POW[N], IPW[N];

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
    POW[0] = 1;
    for(int i = 1; i < N; i++){
        POW[i] = POW[i - 1] * 2 % MOD;
    }
    int inv = bin(2, MOD - 2);
    IPW[0] = 1;
    for(int i = 1; i < N; i++){
        IPW[i] = IPW[i - 1] * inv % MOD;
    }
}

void build(int node, int b, int e){
    if(b == e){
        seg[node] = A[b] * POW[n - b] % MOD;
        return;
    }
    int m = (b + e) >> 1;
    build(2 * node, b, m);
    build(2 * node + 1, m + 1, e);
    seg[node] = ((seg[2 * node] % MOD) + (seg[2 * node + 1] % MOD)) % MOD;
}

void upd(int node, int b, int e, int idx, int v){
    if(b > idx or e < idx) return;
    if(b == e and b == idx){
        seg[node] = v * POW[n - idx] % MOD;
        return;
    }
    int m = (b + e) >> 1;
    upd(2 * node, b, m, idx, v);
    upd(2 * node + 1, m + 1, e, idx, v);
    seg[node] = ((seg[2 * node] % MOD) + (seg[2 * node + 1] % MOD)) % MOD;
}

int query(int node, int b, int e, int l, int r){
    if(b > r or e < l) return 0;
    if(b >= l and e <= r)return seg[node];
    int m = (b + e) >> 1;
    return ((query(2 * node, b, m, l, r) % MOD) + (query(2 * node + 1, m + 1, e, l, r) % MOD)) % MOD;
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cal();
    cin >> n >> q;
    string s;
    cin >> s;
    for(int i = 1; i <= n; i++){
        A[i] = (s[i - 1] - '0');
    }
    build(1, 1, n);
    while (q--){
        int type;
        cin >> type;
        if(type == 1){
            int i;
            cin >> i;
           upd(1, 1, n, i, A[i] ^ 1);
           A[i] ^= 1;
        }else{
            int l, r;
            cin >> l >> r;
            int tot = query(1, 1, n, l, r) * IPW[n - r] % MOD;
            cout << tot << '\n';
        }
    }
    return 0;
}
