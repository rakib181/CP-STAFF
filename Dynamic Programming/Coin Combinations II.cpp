#include<bits/stdc++.h>
using namespace std;
#define int long long int

const int mod = 1e9 + 7;

int ways(vector<int> &ar,int n, int k, vector<int> &dp){
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= k; j++){
            if(j - ar[i - 1] >= 0){
                dp[j] += dp[j - ar[i - 1]];
                dp[j] %= mod;
            }
        }
    }
    return dp[k];
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> ar(n);
    for(int i = 0; i < n; i++){
        cin >> ar[i];
    }
    vector<int> dp(k + 2, 0);
    cout << ways(ar, n, k, dp) << '\n';
    return 0;
}
