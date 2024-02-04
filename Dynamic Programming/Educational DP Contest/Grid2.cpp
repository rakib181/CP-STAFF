#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9, mod = 1e9 + 7;
int f[N], inv_f[N];

int bin(int x, int y){
    int ans = 1;
    while(y){
        if(y & 1) ans = 1LL * ans * x % mod;
        x = 1LL * x * x % mod;
        y >>= 1;
    }
    return ans;
}

void cal(){
    f[0] = 1;
    for(int i = 1; i < N; i++){
        f[i] = 1LL * f[i - 1] * i % mod;
    }
    inv_f[N - 1] = bin(f[N - 1], mod - 2);
    for(int i = N - 2; i >= 0; i--){
        inv_f[i] = 1LL * inv_f[i + 1] * (i + 1) % mod;
    }
}

int nCr(int n, int r){
    if(n < r)return 0;
    return 1LL * f[n] * inv_f[n - r] % mod * inv_f[r] % mod;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cal();
    int h, w, n;
    cin >> h >> w >> n;
    vector<pair<int, int>> a;
    int ans = nCr(h + w - 2, h - 1);
    for(int i = 1; i <= n; i++){
        int x, y;
        cin >> x >> y;
        a.emplace_back(x, y);
    }
    a.emplace_back(h, w);
    sort(a.begin(), a.end());
    int dp[n + 2];
    for(int i = 0; i <= n; i++){
        dp[i] = nCr(a[i].first + a[i].second - 2, a[i].first - 1);
        for(int j = 0; j < i; j++){
           if(a[i].first >= a[j].first and a[i].second >= a[j].second) {
               int cnt = 1LL * dp[j] * nCr(a[i].first - a[j].first + a[i].second - a[j].second, a[i].first - a[j].first) % mod;
               dp[i] = ((dp[i] - cnt) % mod + mod) % mod;
           }
        }
    }
    cout << dp[n] << '\n';
    return 0;
}
