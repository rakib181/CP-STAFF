#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 105, inf = 1e9 + 7;
int d[N][N];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int v; cin >> v;
            d[i][j] = (v >= 0 ? v : inf);
        }
    }
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(d[i][k] + d[k][j] < d[i][j]){
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
           if(d[i][j] != inf) ans = max(ans, d[i][j]);
        }
    }
    cout << ans << '\n';
    return 0;
}
