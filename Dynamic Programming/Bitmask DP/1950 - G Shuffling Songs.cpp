#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<string> g(n), w(n);
        for(int i = 0; i < n; i++){
            cin >> g[i] >> w[i];
        }
        vector<vector<bool>> a(n, vector<bool> (n, false));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                a[i][j] = (g[i] == g[j]) or (w[i] == w[j]);
            }
        }
        vector<vector<int>> dp(1 << n, vector<int> (n, 0));
        for(int i = 0; i < n; i++){
            dp[1 << i][i] = 1;
        }
        int ans = 0;
        for(int msk = 1; msk < (1 << n); msk++){
            for(int i = 0; i < n; i++){
                if(!((msk >> i) & 1))continue;
                for(int j = 0; j < n; j++){
                    if((msk >> j) & 1) continue;
                    int new_msk = msk | (1 << j);
                    if(a[i][j]){
                        dp[new_msk][j] = max(dp[new_msk][j], dp[msk][i] + 1);
                    }
                }
                ans = max(ans, dp[msk][i]);
            }
        }
        cout << n - ans << '\n';
    }
    return 0;
}
