#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9, MX = 30;
int P[N][MX];
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> P[i][0];
    }
 
    for (int d = 1; d < MX; d++) {
        for (int i = 1; i <= n; i++) {
            P[i][d] = P[P[i][d - 1]][d - 1];
        }
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        for (int x = 0; x < MX; x++) {
            if (v & (1 << x)) {
                u = P[u][x];
            }
        }
        cout << u << '\n';
    }
    return 0;
}
