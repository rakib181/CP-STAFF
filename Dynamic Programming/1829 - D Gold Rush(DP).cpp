#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e7 + 9;
int dp[N];

int f(int n, int m, vector<int> &v){
    v.push_back(n);
    if(n == m)return true;
   if(dp[n] != -1)return (dp[n] == 1);
    int l = 1, r = n / 2, ans = -1;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(2 * mid == (n - mid)){
            ans = mid;
            break;
        }
        if(2 * mid > (n - mid))r = mid - 1;
        else l = mid + 1;
    }
    if(ans == -1)return false;
    else {
        return dp[n] = f(ans, m, v) | f((n - ans), m, v);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(dp, -1, sizeof dp);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int> v;
        if(f(n, m, v))cout << "YES\n";
        else cout << "NO\n";
        for(auto  x: v){
            dp[x] = -1;
        }
    }
    return 0;
}
