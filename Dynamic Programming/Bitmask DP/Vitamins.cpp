#include<bits/stdc++.h>
using namespace std;
#define int long long int

const int N = 1e5 + 9, inf = 1e15;
int dp[N][8];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 8; j++){
            dp[i][j] = inf;
        }
    }
    dp[0][0] = 0;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int cost; string s;
        cin >> cost >> s;
        int string_mask = 0;
        for(int pos = 0; pos < 3; pos++){
            char c = (char) ('C' - pos);
            bool have = false;
            for(auto d : s){
                if(c == d){
                   have = true;
                }
            }
            if(have){
                string_mask |= (1 << pos);
            }
        }
        for(int mask = 0; mask < 8; mask++){
            dp[i + 1][mask] = min(dp[i + 1][mask], dp[i][mask]);
            dp[i + 1][mask | string_mask] = min(dp[i + 1][mask | string_mask], dp[i][mask] + cost);
        }
    }
    int ans = dp[n][7];
    if(dp[n][7] == inf) ans = -1;
    cout << ans << '\n';
    return 0;
}
