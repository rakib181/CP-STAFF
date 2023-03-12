#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 505; int n;
int dp[N][N]; vector<int> a, b;

int yo(int i, int j){
    if(i == n + 1 or j == n + 1)return 0;
    if(dp[i][j] != -1)return dp[i][j];
    if(a[i] > b[j]) return dp[i][j] = 2 + yo(i + 1, j + 1);
    else if(a[i] < b[j]) return dp[i][j] = yo(i, j + 1);
    else return dp[i][j] = max(1 + yo(i + 1, j + 1), yo(i, j + 1));
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt, cs = 1;
    cin >> tt;
    while(tt--) {
        cout << "Case " << cs++ << ": ";
        cin >> n;
        a.resize(n + 1), b.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
        }
        sort(a.begin() + 1, a.end(), greater<>());
        sort(b.begin() + 1, b.end(), greater<>());
        memset(dp, -1, sizeof dp);
        cout << yo(1, 1) << '\n';
    }
    return 0;
}
