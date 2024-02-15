#include<bits/stdc++.h>
using namespace std;
using ll = long long;
/*const int N = 1005, mod = 1e9 + 7;
int n, m, dp[N][N];

int f(int i, int lst){
    if(i == m + 1){
        return 1;
    }
    int &ans = dp[i][lst];
    if(ans != -1)return ans;
    ans = 0;
    for(int v = lst; v <= n; v++){
        ans += f(i + 1, v);
        ans %= mod;
    }
    return ans;
}*/

const int N = 2e3 + 9, mod = 1e9 + 7;
int f[N], inv[N];

int power(int x, int y){
    int ans = 1;
    while(y){
        if(y & 1) ans = 1LL * ans * x % mod;
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
    inv[N - 1] = power(f[N - 1], mod - 2);
    for(int i = N - 2; i >= 0; i--){
        inv[i] = 1LL * inv[i + 1] * (i + 1) % mod;
    }
}

int nCr(int n, int r){
    return 1LL * f[n] * inv[r] % mod * inv[n - r] % mod;
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    /*cin >> n >> m;
    m <<= 1;
    memset(dp, -1, sizeof dp);
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans += f(2, i);
        ans %= mod;
    }
    cout << ans << '\n';*/
    cal();
    int n, m;
    cin >> n >> m;
    m <<= 1;
    cout << nCr(n + m - 1, m) << '\n';
    return 0;
}