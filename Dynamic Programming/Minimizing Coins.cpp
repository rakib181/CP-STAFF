#include <bits/stdc++.h>
using namespace std;

#define int long long int

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> ar(n + 1), dp(k + 1, INT_MAX);
    for(int i = 1; i <= n; i++){
        cin >> ar[i];
    }
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= k; j++){
           if(j - ar[i] >= 0) dp[j] = min(dp[j], dp[j - ar[i]] + 1);
        }
    }
    cout <<( (dp[k] != INT_MAX) ? dp[k] : -1) << '\n';
    return 0;
}
