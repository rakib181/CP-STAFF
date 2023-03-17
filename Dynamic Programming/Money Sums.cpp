#include<bits/stdc++.h>
using namespace std;
#define int long long int

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, tot = 0;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        tot += a[i];
    }
    int dp[tot + 1];
    memset(dp, 0, sizeof dp);
    dp[0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = tot; j >= a[i]; j--){
            dp[j] |= dp[j - a[i]];
        }
    }
    cout << accumulate(dp, dp + tot, 0LL) << '\n';
    for(int i = 1; i <= tot; i++){
        if(dp[i])cout << i << ' ';
    }
    return 0;
}
