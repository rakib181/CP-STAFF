#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 105;
int C[N][N];

void cal(){
    for(int i = 0; i < N; i++){
        C[i][i] = 1;
        for(int j = 0; j < i; j++){
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
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
    int n;
    while(cin >> n){
        int m; cin >> m; int ans = 1;
        for(int i = 1; i <= m; i++){
            int k;
            cin >> k;
            ans *= C[n][k];
            n -= k;
        }
        cout << ans << '\n';
    }
    return 0;
}