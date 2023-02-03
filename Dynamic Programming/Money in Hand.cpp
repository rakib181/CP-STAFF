#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;
    cin >> n >> x;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }
    vector<bool> dp(x + 1, false);
    dp[0] = true;
    for(int i = 0; i < n; i++){
        vector<bool> new_dp(dp);
        for(int j = 0; j <= b[i]; j++){
            for(int k = 0; k + j * a[i] <= x; k++){
                new_dp[k + j * a[i]] = new_dp[k + j * a[i]] | dp[k];
            }
        }
        dp = new_dp;
    }
    if(dp[x])cout << "Yes" << '\n';
    else cout << "No" << '\n';
    return 0;
}
