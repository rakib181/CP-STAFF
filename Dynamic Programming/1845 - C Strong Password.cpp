#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 3e5 + 9, K = 10;
int n, m, nxt[N][K], dp[N][K];
string s, l, r;

bool f(int i, int j){
    if(i > n)return true;
    if(j == m)return false;
    if(i >= n)return true;
    int &ret = dp[i][j];
    if(ret != -1)return ret;
    ret = 0;
    for(int k = l[j] - '0'; k <= r[j] - '0'; k++){
        ret |= f(nxt[i][k] + 1, j + 1);
    }
    return ret;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        cin >> s;
        n = (int) s.size();
        cin >> m >> l >> r;
        for (int i = n; i >= 0; i--) {
            for (int j = 0; j < K; j++) {
                nxt[i][j] = (i == n) ? n : nxt[i + 1][j];
            }
            if (i < n)nxt[i][s[i] - '0'] = i;
        }
        for (int i = 0; i < n; i++) {
            memset(dp[i], -1, sizeof dp[i]);
        }
        f(0, 0) ? cout << "YES\n" : cout << "NO\n";
    }
    return 0;
}
