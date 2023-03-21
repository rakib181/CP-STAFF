#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 13;
int dp[N][N];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
        memset(dp, 0, sizeof dp);
        int n, cnt = 0;
        cin >> n;
        for(int i = 0; i < n; i++){
            string s;
            cin >> s;
            for(int j = 0; j < 2; j++){
                for(int c = 0; c < 11; c++){
                    if((char)(c + 'a') == s[j])continue;
                    string a = s; a[j] = (char)(c + 'a');
                    cnt += dp[a[0] - 'a'][a[1] - 'a'];
                }
            }
            dp[s[0] - 'a'][s[1] - 'a'] += 1;
        }
        cout << cnt << '\n';
    }
    return 0;
}
