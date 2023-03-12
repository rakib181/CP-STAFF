#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 1e5 + 9, inf = INT_MIN;
int n; vector<int> a, b, c;
int dp[N][4];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    a.resize(n + 1), b.resize(n + 1), c.resize(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i] >> b[i] >> c[i];
        dp[i][1] = dp[i][2] = dp[i][3] = inf;
    }

    dp[1][1] = a[1], dp[1][2] = b[1], dp[1][3] = c[1];
    for(int i = 2; i <= n; i++){
        dp[i][1] = a[i] + max(dp[i - 1][2], dp[i - 1][3]);
        dp[i][2] = b[i] + max(dp[i - 1][1], dp[i - 1][3]);
        dp[i][3] = c[i] + max(dp[i - 1][1], dp[i - 1][2]);
    }
    cout << max({dp[n][1], dp[n][2], dp[n][3]}) << '\n';
    return 0;
}
