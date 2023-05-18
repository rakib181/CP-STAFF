#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 9, mod = 1e9 + 7;
int f[N];

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
}
int inv(int x){
    return bin(x, mod - 2);
}

int nCr(int n, int r){
    if(n < r)return 0;
    return 1LL * f[n] * inv(1LL * f[r] * f[n - r] % mod) % mod;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cal();
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= k; i++){
        int ans = 1LL *  nCr(n - k + 1, i) * nCr(k - 1, i - 1) % mod;
        cout << ans << '\n';
    }
    return 0;
}
