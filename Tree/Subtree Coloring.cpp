#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 3e5 + 9, mod = 1e9 + 7;
int f[N], inf[N];
vector<int> g[N];
int  sz[N], dp[N][2];

int bin(int x, int y){
    int ans = 1;
    while(y){
        if(y & 1)ans = 1LL * ans * x % mod;
        x = 1LL * x * x % mod;
        y >>= 1;
    }
    return ans;
}

void cal(){
    f[0] = 1;
    for(int i = 1; i < N; i++){
        f[i] = 1LL * f[i - 1] * i % mod;
    }
    inf[N - 1] = bin(f[N - 1], mod - 2);
    for(int i = N - 2; i >= 0; i--){
        inf[i] = 1LL * inf[i + 1] * (i + 1) % mod;
    }
}

int nCr(int n, int r){
    if(r > n)return 0;
    if(r == 0 or r == n)return 1;
    int ans = 1LL * f[n] * inf[r] % mod * inf[n - r] % mod;
    return ans;
}

void dfs(int u, int p){
    int res = 1, cnt = 0;
    sz[u] = 1;
    for(auto v : g[u]){
        if(v != p){
            dfs(v, u);
            sz[u] ^= sz[v];
            res = 1LL * res * dp[v][sz[v]] % mod;
            cnt += sz[v];
        }
    }
    if(sz[u] & 1){
        dp[u][0] = 0;
        dp[u][1] = 1LL * res * (nCr(cnt, cnt / 2 + 1) + nCr(cnt, cnt / 2)) % mod;
    }else{
        dp[u][1] = 0;
        dp[u][0] = 2LL * res % mod * nCr(cnt, cnt / 2) % mod;
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cal();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++){
            g[i].clear();
            sz[i] = 0;
            dp[i][0] = dp[i][1] = 0;
        }
        for(int i = 1; i < n; i++){
            int u, v;
            cin >> u >> v;
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
        dfs(1, -1);
        cout << 1LL * dp[1][sz[1]] * (sz[1] ? 2 : 1) % mod << '\n';
    }
    return 0;
}
