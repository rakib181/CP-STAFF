#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 9, mod = 998244353;
int f[N], inf[N];
int power(int x, int y);
void cal(){
    f[0] = 1;
    for(int i = 1; i < N; i++){
        f[i] = 1LL * f[i - 1] * i % mod;
    }
    inf[N - 1] = power(f[N - 1], mod - 2);
    for(int i = N - 2; i >= 0; i--){
        inf[i] = 1LL * inf[i + 1] * (i + 1) % mod;
    }
}
int power(int x, int y){
    int ans = 1;
    while(y){
        if(y & 1) ans = 1LL * ans * x % mod;
        x = 1LL * x * x % mod;
        y >>= 1;
    }
    return ans;
}

int nCr(int n, int r){
    if(n < 0 or n < r)return 0;
    return 1LL * f[n] * inf[r] % mod * inf[n - r] % mod;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cal();
    int n, m, k;
    cin >> n >> m >> k; int ans = 0;
    for(int i = 0; i <= k; i++){
        ans += 1LL * nCr(n - 1, i) * m % mod * power(m - 1, n - i - 1) % mod;
        ans %= mod;
    }
    cout << ans << '\n';
    return 0;
}
