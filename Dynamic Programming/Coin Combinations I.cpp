#include<bits/stdc++.h>
using namespace std;
#define int long long int

const int mod = 1e9 + 7;

int ways(vector<int> &ar, int k, vector<int> &dp){
    dp[0] = 1;
    for(int i = 0; i <= k; i++){
        for(auto c : ar){
            if(i - c >= 0)dp[i] += dp[i - c], dp[i] %= mod;
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
    cout << ways(ar, k, dp) << '\n';
    return 0;
}
