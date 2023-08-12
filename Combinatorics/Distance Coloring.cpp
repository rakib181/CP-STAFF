#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 105, MOD = 1e9 + 7;
int f[N];

void cal(){
    f[0] = 1;
    for(int i = 1; i < N; i++){
        f[i] = 1LL * f[i - 1] * i % MOD;
    }
}

int bin(int x, int y){
    int ans = 1;
    while (y){
        if(y & 1)ans = 1LL * ans * x % MOD;
        x = 1LL * x * x % MOD;
        y >>= 1;
    }
    return ans;
}

int inv(int x){
    return bin(x, MOD - 2);
}

int ncr(int n, int r){
    int x = f[n];
    int y = inv(f[r]);
    int z = inv(f[n - r]);
    int ans = 1LL * x * y % MOD;
    ans = 1LL * ans * z % MOD;
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cal();
    int t;
    cin >> t;
    while(t--){
       int n, k;
       cin >> n >> k;
       if(n >= k){
           cout << f[k] << '\n';
       }else {
           int x = ncr(k, n);
           cout << 1LL * x * f[n] % MOD << '\n';
       }
    }
    return 0;
}
