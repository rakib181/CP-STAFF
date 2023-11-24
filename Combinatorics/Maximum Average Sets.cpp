#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 55;
ll dp[N][N];

ll nCr(int n, int r){
    if(n == r or r == 0)return 1;
    if(n < r)return 0;
    if(dp[n][r] != -1)return dp[n][r];
    return dp[n][r] = nCr(n - 1, r) + nCr(n - 1, r - 1);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(dp, -1, sizeof dp);
    int n, a, b;
    cin >> n >> a >> b;
    ll v[n + 1];
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    double mean = 0;
    sort(v + 1, v + n + 1);
    reverse(v + 1, v + n + 1);
    for(int i = 1; i <= a; i++){
        mean += v[i];
    }
    mean /= a;
    int last = 0, pos_last = 0;
    for(int i = 1; i <= n; i++){
        if(v[i] == v[a]){
            last += 1;
            if(i <= a){
                pos_last += 1;
            }
        }
    }
    ll ans = 0;
    if(pos_last == a){
        for(int i = a; i <= b; i++){
            ans += nCr(last, i);
        }
    }else{
        ans += nCr(last, pos_last);
    }
    cout << fixed << setprecision(7) << mean << '\n';
    cout << ans << '\n';
    return 0;
}
