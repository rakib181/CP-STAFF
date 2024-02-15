#include<bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
const int N = 105;
int n, m, r, a[N], cnt[N];
ll dp[N][N];

ll f(int i, int k){
    if(i == n + 1){
        return k == r;
    }
    ll &ans = dp[i][k];
    if(ans != -1)return ans;
    ans = 0;
    for(int c = 0; c <= cnt[i]; c++){
        if(k + c <= r)  ans += f(i + 1, k + c);
    }
    return ans;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int cs = 1;
    while(cin >> n >> m and n){
        memset(cnt, 0, sizeof cnt);
        cout << "Case " << cs++ << ":\n";
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            cnt[a[i]] += 1;
        }
        for(int i = 1; i <= m; i++){
            memset(dp, -1, sizeof dp);
            cin >> r;
            cout << f(1, 0) << '\n';
        }
    }
    return 0;
}