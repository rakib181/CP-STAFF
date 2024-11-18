#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e6 + 9, mod = 998244353;
vector<int> mobius(N, 1), d[N];

void cal(){
    for(int i = 2; i < N; i++){
        for(int j = i + i; j < N; j += i){
            mobius[j] -= mobius[i];
        }
    }
    for(int i = 2; i < N; i++){
        for(int j = i; j < N; j += i){
            d[j].emplace_back(i);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cal();
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    vector<int> dp(n + 1), f(N, 0);
    for(int i = 1; i <= n; i++){
        if(i == 1){
            dp[i] = 1;
        }else{
            for(auto x : d[a[i]]){
                 dp[i] += 1LL * mobius[x] * f[x] % mod;
                 if(dp[i] < 0) dp[i] += mod;
                 dp[i] %= mod;
            }
        }
        for(auto x : d[a[i]]){
            f[x] += dp[i];
            f[x] %= mod;
        }
    }
    cout << dp[n] << '\n';
    return 0;
}
