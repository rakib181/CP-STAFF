#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 105;
string dp[N][N]; bool done[N][N];
string a, b;

string LCS(int i, int j){
    if(i >= (int) a.size() or j >= (int) b.size())return "";
    if(done[i][j])return dp[i][j];
    if(a[i] == b[j]){
        return a[i] + LCS(i + 1, j + 1);
    }
    string str1 = LCS(i + 1, j), str2 = LCS(i, j + 1);
    if((int) str1.size() > (int) str2.size()){
        dp[i][j] = str1;
    }else if((int) str1.size() < (int) str2.size()){
        dp[i][j] = str2;
    }else{
        if(str1 < str2){
            dp[i][j] = str1;
        }else dp[i][j] = str2;
    }
    done[i][j] = true;
    return dp[i][j];
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt, cs = 1;
    cin >> tt;
    while (tt--) {
        cout << "Case " << cs++ << ": ";
        cin >> a >> b;
        for(auto & i : dp){
            for(auto & j : i){
                j = "";
            }
        }
        memset(done, false, sizeof done);
        string ans = LCS(0, 0);
        (int) ans.size() == 0 ? cout << ":(" << '\n' : cout << ans << '\n';
    }
    return 0;
}
