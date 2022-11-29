#include <bits/stdc++.h>
using namespace std;

#define int long long int
const int mod = 1e9 + 7;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int>  dp(n + 1, INT_MAX);
    dp[0] = 0;
    for(int i = 0; i <= n; i++){
        for(auto c : to_string(i)){
           if(i - (c - '0') >= 0) dp[i] = min(dp[i], dp[i - (c - '0')] + 1);
        }
    }
    cout << dp[n] << '\n';
    return 0;
}
