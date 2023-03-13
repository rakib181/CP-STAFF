#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int N = 1e5 + 9, inf = INT_MAX;
int dp[N];
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, w;
    cin >> n >> w;
    vector<pair<int, int>> a(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i].first >> a[i].second;
    }
    for(long long & i : dp){
        i = inf;
    }
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
       for(int j = N - 1; j >= a[i].second; j--){
          dp[j] = min(dp[j], dp[j - a[i].second] + a[i].first);
       }
    }
    for(int i = N - 1; i >= 0; i--){
        if(dp[i] <= w) {
            cout << i << '\n';
            break;
        }
    }
    return 0;
}
