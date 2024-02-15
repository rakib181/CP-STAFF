#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 35;
ll C[N][N], F[N];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    F[0] = 1;
    for(int i = 0; i < N; i++){
        C[i][i] = 1;
        if(i)F[i] = F[i - 1] * i;
        for(int j = 0; j < i; j++){
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        }
    }
    int t, cs = 1;
    cin >> t;
    while(t--){
        cout << "Case " << cs++ << ": ";
        int n, k;
        cin >> n >> k;
        cout << (k > n ? 0 : C[n][k] * C[n][k] * F[k]) << '\n';
    }
    return 0;
}
