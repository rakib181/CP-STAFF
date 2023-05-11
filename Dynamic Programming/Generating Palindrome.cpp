#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const  int N = 105;
int n, dp[N][N];
string s;

int f(int i, int j){
    if(i >= j)return 0;
    if(dp[i][j] != -1)return dp[i][j];
    int ans = INT_MAX;
    if(s[i] == s[j])ans = min(ans, f(i + 1, j - 1));
    else{
        ans = min(ans, 1 + f(i + 1, j));
        ans = min(ans, 1 + f(i, j - 1));
    }
    return dp[i][j] = ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, cs = 1;
    cin >> t;
    while(t--) {
        for (auto &i: dp) {
            for (int &j: i) {
                j = -1;
            }
        }
        cin >> s;
        cout << "Case " << cs++  << ": " <<  f(0, (int) s.size() - 1) << '\n';
    }
    return 0;
}
