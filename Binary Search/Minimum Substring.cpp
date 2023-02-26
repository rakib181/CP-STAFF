#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int n = (int) s.size(), l = 1, r = n - 1, ans = n;
    vector<int> vis(27, 0);
    int need = 0;
    for(auto x : s){
        if(vis[x - 'a'] == 0){
            need += 1;
        }
        vis[x - 'a'] += 1;
    }
    auto possible = [&](int x){
        for(int i = 0; i < 27; i++){
            vis[i] = 0;
        }
        int cnt = 0;
         for(int i = 0; i < x; i++){
             if(vis[s[i] - 'a'] == 0){
                 cnt += 1;
             }
             vis[s[i] - 'a'] += 1;
         }
        if(cnt == need)return true;
        int pt = x;
        while (pt < n){
            if(vis[(s[pt] - 'a')] == 0){
                cnt += 1;
            }
            vis[(s[pt] - 'a')] += 1;
            vis[(s[(pt - x)] - 'a')] -= 1;
            if(vis[(s[(pt - x)] - 'a')] == 0){
                cnt -= 1;
            }
            pt += 1;
            if(cnt == need) return true;
        }
        return cnt == need;
    };
    while (l <= r){
        int m = (l + r) >> 1;
        if(possible(m)){
            ans = min(ans, m);
            r = m - 1;
        }else l = m + 1;
    }
    cout << ans << '\n';
    return 0;
}
