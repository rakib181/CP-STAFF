#include<bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    string s, ss;
    cin >> s >> ss;
    vector<int> freq(26, 0);
    for(auto x : ss){
        freq[x - 'a']++;
    }
    int l = 0, r = 0, ans = 0;
    while (r < n){
        if(freq[s[r] - 'a'] > 0){
            freq[s[r] - 'a']--;
            ans += (r - l + 1);
        }else{
            while (freq[s[r] - 'a'] <= 0){
                freq[s[l++] - 'a']++;
            }
            if(freq[s[r] - 'a'] > 0){
                freq[s[r] - 'a']--;
                ans += (r - l + 1);
            }
        }
        r++;
    }
    cout << ans << '\n';
    return 0;
}
