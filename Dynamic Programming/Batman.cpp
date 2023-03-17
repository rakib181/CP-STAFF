#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 55;
int dp[N][N][N];
string a, b, c;

int LCS(int i, int j, int k){
    if(i >= (int) a.size() or j >= (int) b.size() or k >= (int) c.size())return 0;
    if(dp[i][j][k] != -1)return dp[i][j][k];
    if(a[i] == b[j] and b[j] == c[k]){
        return 1 + LCS(i + 1, j + 1, k + 1);
    }
    return dp[i][j][k] = max({LCS(i + 1, j , k), LCS(i, j + 1, k), LCS(i, j, k + 1)});

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt, cs = 1;
    cin >> tt;
    while (tt--) {
        cout << "Case " << cs++ << ": ";
        cin >> a >> b >> c;
        memset(dp, -1, sizeof dp);
        cout << LCS(0, 0, 0) << '\n';
    }
    return 0;
}
