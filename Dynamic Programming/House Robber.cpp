#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 1e5 + 9;
int dp[N];    int n;

int cal(int i, vector<int> &A){
    if(i < 1) return 0;
    if(dp[i] != -1) return dp[i];
    return dp[i] = max(cal(i - 1, A), cal(i - 2, A) + A[i]);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    memset(dp, -1, sizeof dp);
    dp[0] = 0, dp[1] = a[1];
    cal(n, a);
    cout << dp[n] << '\n';
    return 0;
}
