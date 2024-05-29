#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int> (n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    const ll inf = -1e18 + 9;
    vector<pair<ll, int>> dp(1 << n);
    dp[0] = {0, 0};
    for(int msk = 1; msk < (1 << n); msk++){
        dp[msk] = {inf, 0};
        for(int bit = 0; bit < n; bit++){
            if(msk >> bit & 1){
                int nw_msk = msk ^ (1 << bit);
                if(dp[msk].first <= dp[nw_msk].first){
                    dp[msk] = {dp[nw_msk].first, 1 << bit};
                }
                ll score = 0;
                for(int j = 0; j < n; j++){
                    if((dp[nw_msk].second >> j) & 1){
                       score += a[bit][j];
                    }
                }
                if(dp[msk].first <= dp[nw_msk].first + score){
                    dp[msk] = {dp[nw_msk].first + score, dp[nw_msk].second | (1 << bit)};
                }
            }
        }
    }
    cout << max(0LL, dp[(1 << n) - 1].first);
    return 0;
}
