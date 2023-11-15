#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9, mod = 1e9 + 7;
int f[N], inv_f[N];

int bin(int x, int y){
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
    inv_f[N - 1] = bin(f[N - 1], mod - 2);
    for(int i = N - 2; i >= 0; i--){
        inv_f[i] = 1LL * inv_f[i + 1] * (i + 1) % mod;
    }
}

int nCr(int n, int r){
    if(n < r)return 0;
    return 1LL * f[n] * inv_f[n - r] % mod * inv_f[r] % mod;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cal();
    int h, w, a, b;
    cin >> h >> w >> a >> b;
    int ans = 0;
    for(int i = b + 1; i <= w; i++){
        int l = nCr((h - a - 1) + i - 1, i - 1);
        int r = nCr(a - 1 + w - i, w - i);
        ans = 1LL * (1LL * ans + (1LL * l * r) % mod) % mod;
    }
    cout << ans << '\n';
    return 0;
}
