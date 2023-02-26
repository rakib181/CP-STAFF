#include<bits/stdc++.h>
using namespace std;
#define int long long int

const int N = 2, MOD = 998244353;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<int, int>> a(n + 1); vector<int> dp[N];
    for(int i = 1; i <= n; i++){
        cin >> a[i].first >> a[i].second;
    }
    dp[0].assign(n + 1, 0);
    dp[1].assign(n + 1, 0);
    dp[0][1] = 1, dp[1][1] = 1;
    for(int i = 2; i <= n; i++){
        if(a[i].first != a[i - 1].first){
            dp[0][i] = (dp[0][i] + dp[0][i - 1]) % MOD;
        }
        if(a[i].first != a[i - 1].second){
            dp[0][i] = (dp[0][i] + dp[1][i - 1]) % MOD;
        }
        if(a[i].second != a[i - 1].first){
            dp[1][i] = (dp[1][i] + dp[0][i - 1]) % MOD;
        }
        if(a[i].second != a[i - 1].second){
            dp[1][i] = (dp[1][i] + dp[1][i - 1]) % MOD;
        }
    }
    cout << (dp[0][n] + dp[1][n]) % MOD << '\n';
    return 0;
}
