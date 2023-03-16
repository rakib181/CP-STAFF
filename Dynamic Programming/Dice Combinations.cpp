#include <bits/stdc++.h>
using namespace std;

#define int long long int
const int mod = 1e9 + 7;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int>  dp(n + 1, 0);
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 6; j++){
           if(i - j >= 0) dp[i] += (dp[i - j]) % mod, dp[i] %= mod;
        }
    }
    cout << dp[n] << '\n';
    return 0;
}

// Recursive Approach
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 1e6 + 9, MOD = 1e9 + 7;
int dp[N], n;

int comb(int i){
    if(i < 0)return 0;
    if(i == 0) return 1;
    if(dp[i] != -1)return dp[i];
    int ans = 0;
    for(int j = 1; j <= 6; j++){
        ans = ans + comb(i - j);
        ans %= MOD;
    }
    return dp[i] = ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    memset(dp, -1, sizeof dp);
    comb(n);
    cout << dp[n] << '\n';
    return 0;
}
