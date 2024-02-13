#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<vector<char>> a(n + 1, vector<char> (n + 1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        int c = 0;
        for(int j = 1; j <= n; j++){
            c += (a[i][j] == 'C');
        }
        ans += c * (c - 1) / 2;
    }
    for(int j = 1; j <= n; j++){
        int c = 0;
        for(int i = 1; i <= n; i++){
            c += (a[i][j] == 'C');
        }
        ans += c * (c - 1) / 2;
    }
    cout << ans << '\n';
    return 0;
}