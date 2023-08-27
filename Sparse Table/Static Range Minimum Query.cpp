#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9, K = 20, inf = 1e9 + 7;
int st[K][N];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < K; i++){
        for(int j = 0; j < n; j++){
            st[i][j] = inf;
        }
    }
    for(int i = 0; i < n; i++){
       st[0][i] = a[i];
    }
    for(int i = 1; i < K; i++){
        for(int j = 0; j + ((1 << (i - 1))) <= n; j++){
            st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
        }
    }
    while(q--){
        int l, r;
        cin >> l >> r;
        l -= 1, r -= 1;
        int ans = INT_MAX;
        for(int k = K - 1; k >= 0; k--){
            if((1 << k) <= (r - l + 1)){
                ans = min(ans, st[k][l]);
                l += (1 << k);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
