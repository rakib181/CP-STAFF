#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9, mod = 1e9 + 7;

int bin(int x, int y){
    int ans = 1;
    while(y){
        if(y & 1)ans = 1LL * ans * x % mod;
        x = 1LL * x * x % mod;
        y >>= 1;
    }
    return ans;
}

int f[N], inf[N];

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
    int ans = 1LL * f[n] * inf[r] % mod * inf[n - r] % mod;
    return ans;
}

vector<int> g[N];
int a[N];
ll sum[N];

void dfs(int u, int p){
    sum[u] = a[u];
    for(auto v : g[u]){
        if(v != p){
            dfs(v, u);
            sum[u] += sum[v];
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cal();
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        for(int i = 0; i <= n; i++){
            g[i].clear();
            sum[i] = 0;
        }
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        for(int i = 1; i < n; i++){
            int u, v;
            cin >> u >> v;
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
        dfs(1, 0);
        if(sum[1] % x){
            for(int i = 1; i <= n; i++){
                cout << "0 ";
            }
            cout << '\n';
        }else{
            int cnt = 0;
            for(int i = 2; i <= n; i++){
                if(sum[i] % x == 0)cnt += 1;
            }
            for(int i = 1; i <= n; i++){
                cout << nCr(cnt, i - 1) << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}
