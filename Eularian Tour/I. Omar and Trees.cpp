#include<bits/stdc++.h>
using namespace std;
#define long long long int

using u64 = uint64_t;
using u128 = __uint128_t;
u64 bin(u64 x, u64 y, u64 MOD){
    u64 ans = 1;
    x %= MOD;
    while (y){
        if(y & 1) ans = (u128) ans * x % MOD;
        x = (u128) x * x % MOD;
        y >>= 1;
    }
    return ans;
}

bool check_composite(u64 n, u64 a, u64 d, int s){
    u64 x = bin(a, d, n);
    if(x == 1 or x == n - 1)return false;
    for(int i = 1; i <= s; i++){
        x = (u128) x * x % n;
        if(x == n - 1)return false;
    }
    return true;
}

bool millerRobin(u64 n){
    if(n < 2)return false;
    u64 d = n - 1; int s = 0;
    while (!(d & 1)){
        d >>= 1;
        s++;
    }
    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a)
            return true;
        if (check_composite(n, a, d, s))
            return false;
    }
    return true;
}

const int N = 1e5 + 9;
int n;
vector<int> g[N], a(N), in(N), fin(N);
vector<long> t(4 * N), lazy(4 * N);

long merge(long x, long y){
    return x + y;
}

void push(int node, int b, int e){
    if(lazy[node] == 0)return;
    t[node] = 1LL * (e - b + 1) * lazy[node];
    if(b != e){
        lazy[2 * node] = lazy[node];
        lazy[2 * node + 1] = lazy[node];
    }
    lazy[node] = 0;
}

void upd(int node, int b, int e, int l, int r, int v){
    push(node, b, e);
    if(b > r or e < l)return;
    if(b >= l and e <= r){
        lazy[node] = v;
        push(node, b, e);
        return;
    }
    int m = (b + e) >> 1;
    upd(2 * node, b, m, l, r, v);
    upd(2 * node + 1, m + 1, e, l, r, v);
    t[node] = merge(t[2 * node], t[2 * node + 1]);
}

long query(int node, int b, int e, int l, int r){
    push(node, b, e);
    if(b > r or e < l)return 0;
    if(b >= l and e <= r)return t[node];
    int m = (b + e) >> 1;
    return merge(query(2 * node, b, m, l, r), query(2 * node + 1, m + 1, e, l, r));
}
int tme;

void dfs(int u, int p){
    in[u] = ++tme;
    upd(1, 1, n, in[u], in[u], a[u]);
    for(auto v : g[u]){
        if(v == p)continue;
        dfs(v, u);
    }
    fin[u] = tme;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    tme = 0;
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs(1, 0);
    int q;
    cin >> q;
    while (q--){
        int type;
        cin >> type;
        if(type == 1){
            int u, v;
            cin >> u >> v;
            upd(1, 1, n, in[u], fin[u], v);
        }else{
            int u;
            cin >> u;
            long s = query(1, 1, n, in[u], fin[u]);
            if(s <= 3)cout << "NO\n";
            else{
                if(s & 1){
                    if(millerRobin(s - 2)){
                        cout << "YES\n";
                    }else cout << "NO\n";
                }else{
                    cout << "YES\n";
                }
            }
        }
    }
    return 0;
}
