#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 1e5, MOD = 10000007;
int dp[N];
int a, b, c, d, e, f, _n;

int fun(int n){
    if (n == 0) return dp[n] = a;
    if (n == 1) return dp[n] = b;
    if (n == 2) return dp[n] = c;
    if (n == 3) return dp[n] = d;
    if (n == 4) return dp[n] = e;
    if (n == 5) return dp[n] = f;
    if(dp[n] != -1)return dp[n];
    return dp[n] =  (((((fun(n-1) + fun(n-2)) % MOD) + (fun(n-3) + (fun(n-4) % MOD))) % MOD) + ((fun(n-5) + (fun(n-6)) % MOD) % MOD)) % MOD;
}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt, cs = 1;
    cin >> tt;
    while (tt--) {
        cout << "Case " << cs++ << ": ";
        cin >> a >> b >> c >> d >> e >> f >> _n;
        memset(dp, -1, N);
        fun(_n);
        cout << (dp[_n] % MOD) << '\n';
    }
    return 0;
}
