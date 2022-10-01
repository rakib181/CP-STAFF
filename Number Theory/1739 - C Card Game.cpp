#include <bits/stdc++.h>
using namespace std;

const int N = 65, MOD = 998244353;
vector<long long> fact(N), MOD_INV(N), INV_FACT(N);

long long bin_pow(long long a, long long b, long long mod){
    long long ans = 1LL;
    while(b){
        if(b & 1)ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

void precal(){
    fact[0] = fact[1] = 1;
    for(int i = 2; i < N; i++){
        fact[i] = fact[i - 1] * i % MOD;
    }
    for(int i = 1; i < N; i++){
        MOD_INV[i] = bin_pow(i, MOD - 2, MOD);
    }
    INV_FACT[0] = INV_FACT[1] = 1;
    for(int i = 2; i < N; i++){
        INV_FACT[i] = (MOD_INV[i] * INV_FACT[i - 1]) % MOD;
    }
}

long long nCr(long long n, long long r){
    if(r > n or n < 0 or r < 0)return 0;
    return fact[n] * INV_FACT[r] % MOD * INV_FACT[n - r] % MOD;
}

long long call(int n, int alice){
    if(n == 2){
        if(alice){
            return 1;
        }
        return 0;
    }

    long long ans = 0;
    if(alice){
        ans = nCr(n - 1, (n / 2) - 1);
        ans += call(n - 2, alice ^= 1);
        ans %= MOD;
    }else{
        ans = nCr(n - 2, (n / 2) - 2);
        ans += call(n - 2, alice ^= 1);
        ans %= MOD;
    }
    return ans;
}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    precal();
    int tt;
    cin >> tt;
    while (tt--){
        int n;
        cin >> n;
        long long alice = call(n, 1) % MOD;
        long long borris = call(n, 0) % MOD;
        long long draw = ((nCr(n, n / 2) - alice + MOD) % MOD - borris + MOD) % MOD;
        cout << alice << ' ' << borris << ' ' << draw << '\n';
    }
    return 0;
}
