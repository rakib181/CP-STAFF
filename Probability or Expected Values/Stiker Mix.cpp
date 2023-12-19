#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 9, mod = 1e9 + 7;
int f[N], d[N];

void cal(){
    f[0] = 1;
    for(int i = 1; i < N; i++){
        f[i] = 1LL * f[i - 1] * i % mod;
    }
}

int bin(int x, int y){
    int ans = 1;
    while(y){
        if(y & 1) ans = 1LL * ans * x % mod;
        x = 1LL * x * x % mod;
        y >>= 1;
    }
    return ans;
}

int nCr(int n, int r){
    if(n < r)return 0;
    if(r == 0)return 1;
    if(r == 1)return n;
    if(n == 1)return 1;
    int ans = 1LL * f[n] * bin(1LL * f[r] * f[n - r] % mod, mod - 2) % mod;
    return ans;
}

int de(int n){
    if(n == 1)return d[n] = 0;
    if(n == 2)return d[n] = 1;
    if(d[n] != -1)return d[n];
    return d[n] = 1LL * (n - 1) * (((de(n - 1) % mod + de(n - 2) % mod) % mod) % mod) % mod;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cal();
    memset(d, -1, sizeof d);
    d[0] = 1;
    for(int i = 1; i < N; i++){
        de(i);
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = n; i >= 0; i--){
            cout << 1LL * d[i] * nCr(n, i) % mod * bin(f[n], mod - 2) % mod << ' ';
        }
        cout << '\n';
    }
    return 0;
}
