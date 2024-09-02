#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int n = (int) s.size();
    vector<int> dp((1 << 20), 0);
    for(int i = 0; i < n; i++){
        vector<int> vis(20, 0);
        int msk = 0;
        for(int j = i; j < min(n, i + 20); j++){
            if(vis[s[j] - 'a'])break;
            vis[s[j] - 'a'] = 1;
            msk |= (1 << (s[j] - 'a'));
            dp[msk] = __builtin_popcount(msk);
        }
    }
    for(int msk = 0; msk < (1 << 20); msk++){
        for(int i = 0; i < 20; i++){
            if(msk >> i & 1){
                dp[msk] = max(dp[msk], dp[msk ^ (1 << i)]);
            }
        }
    }
    int ans = 0;
    for(int msk = 0; msk < (1 << 20); msk++){
        int invMsk = msk ^ ((1 << 20) - 1);
        ans = max(ans, dp[msk] + dp[invMsk]);
    }
    cout << ans;
    return 0;
}
