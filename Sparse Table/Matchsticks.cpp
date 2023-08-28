#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9, K = 20, inf = 1e9 + 7;
int mx[K][N], mn[K][N];

int query_mx(int l, int r){
    if(l > r) return 0;
    int ans = INT_MIN;
    for(int i = K - 1; i >= 0; i--){
        if((1 << i) <= (r - l + 1)){
            ans = max(ans, mx[i][l]);
            l += (1 << i);
        }
    }
    return ans;
}
int query_mn(int l, int r){
    if(l > r)return 0;
    int ans = INT_MAX;
    for(int i = K - 1; i >= 0; i--){
        if((1 << i) <= (r - l + 1)){
            ans = min(ans, mn[i][l]);
            l += (1 << i);
        }
    }
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < K; i++){
        for(int j = 0; j < n; j++){
            mx[i][j] = 0, mn[i][j] = inf;
        }
    }
    for(int i = 0; i < n; i++){
        mx[0][i] = a[i];
        mn[0][i] = a[i];
    }
    for(int i = 1; i < K; i++){
        for(int j = 0; j + (1 << (i - 1)) <= n; j++){
            mx[i][j] = max(mx[i - 1][j], mx[i - 1][j + (1 << (i - 1))]);
            mn[i][j] = min(mn[i - 1][j], mn[i - 1][j + (1 << (i - 1))]);
        }
    }
    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        int ans = query_mn(l, r);
        int m = ans;
        int x = query_mx(l, r);
        double need = (x - m) / 2.0;
        double left = query_mx(0, l - 1);
        double right = query_mx(r + 1, n - 1);
        cout << fixed << setprecision(1) << 1.0 * ans + max({need, left, right}) << '\n';
    }
    return 0;
}
