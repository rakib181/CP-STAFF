#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9, K = 20, inf = 1e9 + 7;
int gc[K][N], lg[N];

int query(int l, int r){
    int k = lg[r - l];
    return min(gc[k][l], gc[k][r - (1 << k)]);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i = 2; i < N; i++){
        lg[i] = lg[(i >> 1)] + 1;
    }
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < K; i++){
        for(int j = 0; j < n; j++){
            gc[i][j] = inf;
        }
    }
    for(int i = 0; i < n; i++){
        gc[0][i] = a[i];
    }
    for(int i = 1; i < K; i++){
        for(int j = 0; j + (1 << (i - 1)) <= n; j++){
            gc[i][j] = min(gc[i - 1][j], gc[i - 1][j + (1 << (i - 1))]);
        }
    }
    if(k == 1){
        cout << *min_element(a, a + n) << '\n';
    }else if(k >= 3)cout << *max_element(a, a + n) << '\n';
    else {
        int ans = INT_MIN;
        for(int i = 0; i < n; i++){
            ans = max(ans, max(query(0, i + 1), query(i, n)));
        }
        cout << ans << '\n';
    }
    return 0;
}
