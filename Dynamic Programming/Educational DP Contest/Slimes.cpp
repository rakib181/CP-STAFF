#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 405;
const ll inf = 1e18;
int n, a[N]; ll dp[N][N], prefix[N];

ll cost(int l, int r){
    return prefix[r] - prefix[l - 1];
}

ll rec(int l, int r){
    if(l == r)return 0;
    if(dp[l][r] != -1)return dp[l][r];
    ll ans = inf;
    for(int i = l; i < r; i++){
        ans = min(ans, rec(l, i) + rec(i + 1, r) + cost(l, r));
    }
    return dp[l][r] = ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        prefix[i] = prefix[i - 1] + a[i];
    }
    memset(dp, -1, sizeof dp);
    cout << rec(1, n) << '\n';
    return 0;
}
