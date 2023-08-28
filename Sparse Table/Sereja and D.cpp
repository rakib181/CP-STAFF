#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9, K = 20;
int mx[K][N];

int query(int l, int r){
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


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int x[n], a[n];
    for(int i = 0; i < n; i++){
        cin >> x[i];
        if(i)a[i] = x[i] - x[i - 1];
    }
    for(int i = 0; i < K; i++){
        for(int j = 0; j < n; j++){
            mx[i][j] = 0;
        }
    }
    for(int i = 0; i < n; i++){
        mx[0][i] = a[i];
    }
    for(int i = 1; i < K; i++){
        for(int j = 0; j + (1 << (i - 1)) <= n; j++){
            mx[i][j] = max(mx[i - 1][j], mx[i - 1][j + (1 << (i - 1))]);
        }
    }
    int q;
    cin >> q;
    while(q--){
        int t, d;
        cin >> t >> d;
        int k = (int) (upper_bound(x, x + n, t) - x);
        k -= 1;
        int l = 1, r = k, ans = k + 1;
        while(l <= r){
            int m = (l + r) >> 1;
            if(query(m, k) <= d){
                ans = m;
                r = m - 1;
            }else l = m + 1;
        }
        cout << ans << '\n';
    }
    return 0;
}
