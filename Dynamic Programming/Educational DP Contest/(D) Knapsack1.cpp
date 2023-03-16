#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int NX = 105, N = 1e5 + 9;
int dp[NX][N];    int n, w;

int cal(int i, int weight, vector<int> &W, vector<int> &A){
    if(i == n + 1)return 0;
    if(dp[i][weight] != -1)return dp[i][weight];
    int ans = cal(i + 1, weight, W, A);
    if(weight + W[i] <= w) ans = max(ans, cal(i + 1, weight + W[i], W, A) + A[i]);
    return dp[i][weight] = ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> w;
    vector<int> A(n + 1), W(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> W[i] >> A[i];
    }
    memset(dp, -1, sizeof dp);
    cout <<   cal(1, 0, W, A) << '\n';
    return 0;
}
