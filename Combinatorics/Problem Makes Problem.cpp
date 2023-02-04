#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 3e6 + 5, MOD = 1e9 + 7;
vector<int> fact(N);

int bin(int a, int b){
    int ans = 1;
    while (b){
        if(b & 1) ans = ans * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ans;
}
void cal(){
    fact[0] = fact[1] = 1;
    for(int i = 2; i < N; i++){
        fact[i] = (((i % MOD) * (fact[i - 1] % MOD)) % MOD);
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cal();
    int tt, cs = 1;
    cin >> tt;
    while (tt--){
        cout << "Case " << cs++ << ": ";
        int n, r;
        cin >> n >> r;
        n = n + r - 1, r = r - 1;
        int x = ((fact[r] % MOD) * (fact[n - r] % MOD)) % MOD;
        int modInv = bin(x, MOD - 2);
        cout << (((fact[n] % MOD) * (modInv % MOD)) % MOD) << '\n';
    }
    return 0;
}
