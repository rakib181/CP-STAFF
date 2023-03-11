#include<bits/stdc++.h>
using namespace std;
#define int long long int

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
       int n, ans = INT_MIN;
       cin >> n;
       string s;
       cin >> s;
       int l = 0; map<char, int> freq;
       for(int r = 0; r < n; r += 1){
           freq[s[r]] += 1;
           if(freq[s[r]] > (s[r] - 'a' + 1)){
               while (s[l] != s[r]) {
                   freq[s[l]] -= 1;
                   l += 1;
               }
               freq[s[l]] -= 1;
               l += 1;
               ans = max(ans, r - l + 1);
           }
           ans = max(ans, r - l + 1);
       }
       cout << ans << '\n';
    }
    return 0;
}
