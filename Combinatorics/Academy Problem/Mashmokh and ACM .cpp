#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2005, mod = 1e9 + 7;

vector<int> d[N];

void cal(){
    for(int i = 1; i < N; i++){
        for(int j = i; j < N; j += i){
            d[i].emplace_back(j);
        }
    }
}
int n, k, dp[N][N];

int f(int cur, int cnt){
    if(cnt == 0){
        return 1;
    }
    if(dp[cur][cnt] != -1)return dp[cur][cnt];
    int ans = 0;
    for(auto x : d[cur]){
        if(x > n)break;
        ans += f(x, cnt - 1);
        ans %= mod;
    }
    return dp[cur][cnt] = ans;
}

void reset(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            dp[i][j] = -1;
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cal();
    cin >> n >> k;
    int ans = 0;
    reset();
    for(int i = 1; i <= n; i++){
        ans += f(i, k - 1);
        ans %= mod;
    }
    cout << ans << '\n';
    return 0;
}