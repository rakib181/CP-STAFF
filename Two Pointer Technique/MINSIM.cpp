#include<bits/stdc++.h>
using namespace std;
#define int long long int

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    vector<int> fs(26, 0), ft(26, 0);
    for(auto x : t){
        ft[x - 'a'] += 1;
    }
    auto check = [&](){
        for(int i = 0; i < 26; i++){
            if(ft[i]  and ft[i] > fs[i])return false;
        }
        return true;
    };
    int l = 0, st = 0, ans = INT_MAX;
    for(int r = 0; r < (int) s.size(); r++){
          fs[s[r] - 'a'] += 1;
        while (check()){
            if(ans > (r - l + 1)){
                st = l;
                ans = r - l + 1;
            }
            fs[s[l] - 'a'] -= 1;
            l += 1;
        }
    }
    if(ans == INT_MAX)cout << "IMPOSSIBLE" << '\n';
    else {
        cout << ans << '\n' << s.substr(st, ans) << '\n';
    }
    return 0;
}
