#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 100;
ll dp[N][2];

ll f(int n, int lst){
    if(n < 0)return 0;
    if(n == 0)return 1;
    if(dp[n][lst] != -1)return dp[n][lst];
    ll ans = 0;
    if(lst == 0){
        ans += f(n - 1, 0) + f(n - 1, 1);
    }else{
        ans += f(n - 1, 0);
    }
    return dp[n][lst] = ans;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t, cs = 1;
    cin >> t;
    while(t--){
        cout << "Scenario #" << cs++ << ":\n";
        int n;
        cin >> n;
        for(int i = 0; i <= n; i++){
            dp[i][0] = dp[i][1] = -1;
        }
        ll ans = f(n - 1, 0);
        for(int i = 0; i <= n; i++){
            dp[i][0] = dp[i][1] = -1;
        }
        ans += f(n - 1, 1);
        cout << ans << "\n\n";
    }
    return 0;
}