#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e6 + 9, MOD = 1e9 + 7;
int f[N];
 
void cal(){
    f[0] = f[1] = 1;
    for(int i = 2; i < N; i++){
        f[i] = 1LL * f[i - 1] * i % MOD;
    }
}
 
int bin(int x, int y){
    int ans = 1;
    while(y){
        if(y & 1)ans = 1LL * ans * x % MOD;
        x = 1LL * x * x % MOD;
        y >>= 1;
    }
    return ans;
}
 
int inv(int x){
    return bin(x, MOD - 2);
}
 
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cal();
    int n, k;
    cin >> n >> k;
    int sANDb = n + k - 1;
    int den = 1LL * f[n - 1] * f[k] % MOD;
    cout << 1LL * f[sANDb] * inv(den) % MOD << '\n';
    return 0;
}
