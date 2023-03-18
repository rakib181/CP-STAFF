#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 65;
int dp[N];

int f(int n){
    if(n == 0) return 1;
    if(dp[n] != -1)return dp[n];
    return dp[n] = 2 * f(n - 2);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    memset(dp, -1, sizeof dp);
    cout << f(n) << '\n';
    return 0;
}
