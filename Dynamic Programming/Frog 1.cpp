#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 1e5 + 9, inf = INT_MAX;
int n; vector<int> a;
int dp[N];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    a.resize(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        dp[i] = inf;
    }
    dp[1] = 0;
    for(int i = 1; i <= n; i++){
        if(i - 1 >= 1)dp[i] = min(dp[i], (dp[i - 1] + abs(a[i] - a[i - 1])));
        if(i - 2 >= 1)dp[i] = min(dp[i], (dp[i - 2] + abs(a[i] - a[i - 2])));
    }
    cout << dp[n] << '\n';
    return 0;
}
