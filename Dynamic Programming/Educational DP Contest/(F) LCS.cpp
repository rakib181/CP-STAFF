#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 3005;
int dp[N][N];
string s, t;

int LCS(int i, int j){
    if(i >= (int) s.size() or j >= (int) t.size())return 0;
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    int ans = LCS(i + 1, j);
    ans = max(ans, LCS(i, j + 1));
    if(s[i] == t[j]) ans = max(ans, LCS(i + 1, j + 1) + 1);
    return dp[i][j] = ans;
}

void print(int i, int j){
    if(i >= (int) s.size() or j >= (int) t.size())return;
    if(s[i] == t[j]){
        cout << s[i];
        print(i + 1, j + 1);
        return;
    }
    int x = LCS(i + 1, j);
    int y = LCS(i, j + 1);
    if(x >= y){
        print(i + 1, j);
    }else{
        print(i, j + 1);
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s >> t;
    memset(dp, -1, sizeof dp);
    print(0, 0);
    return 0;
}
