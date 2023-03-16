#include <bits/stdc++.h>
using namespace std;

#define int long long int
const int mod = 1e9 + 7;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int>  dp(n + 1, INT_MAX);
    dp[0] = 0;
    for(int i = 0; i <= n; i++){
        for(auto c : to_string(i)){
           if(i - (c - '0') >= 0) dp[i] = min(dp[i], dp[i - (c - '0')] + 1);
        }
    }
    cout << dp[n] << '\n';
    return 0;
}

\\ Recursive Approach
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 1e6 + 9, MOD = 1e9 + 7;
int dp[N], n;

int yo(int i){
    if(i == 0)return 0;
    if(dp[i] != -1)return dp[i];
    int ans = INT_MAX;
    string s = to_string(i);
    for(auto x : s){
       if((x - '0' >= 1) and (i - (x - '0') >= 0)) ans = min(ans, yo(i - (x - '0')) + 1);
    }
    return dp[i] = ans;
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    memset(dp, -1, sizeof dp);
    yo(n);
    cout << dp[n] << '\n';
    return 0;
}
