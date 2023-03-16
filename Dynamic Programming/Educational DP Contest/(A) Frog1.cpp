#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 1e5 + 9;
int dp[N];

int cal(int i, vector<int> &a){
    if(i == 1)return 0;
    if(dp[i] != -1)return dp[i];
    return dp[i] = min(cal(i - 1, a) + abs(a[i] - a[i - 1]), cal(i - 2, a) + abs(a[i] - a[i - 2]));
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    memset(dp, -1, sizeof dp);
    dp[0] = dp[1] = 0, dp[2] = dp[1] + abs(a[1] - a[2]);
    cal(n, a);
    cout << dp[n] << '\n';
    return 0;
}
