#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 1005;
int dp[N][N];
string s;
int pal(int x, int y){
    if(x > y) return 0;
    if(dp[x][y] != -1)return dp[x][y];
    int ans = 0;
    if(s[x] == s[y]){
        if(x != y)ans = 2;
        else ans = 1;
        ans += pal(x + 1, y - 1);
    }
    ans = max(ans, pal(x + 1, y));
    ans = max(ans, pal(x, y - 1));
    return dp[x][y] = ans;
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    cin.ignore();
    while (tt--){
        getline(cin, s);
        memset(dp, -1, sizeof dp);
        cout << pal(0, (int) s.size() - 1) << '\n';
    }
    return 0;
}
