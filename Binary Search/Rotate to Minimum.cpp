#include<bits/stdc++.h>
using namespace std;
#define int long long

pair<int, int> check(const string& s, int p, int q, int m){
     vector<pair<int, int>> costs;
     for(int i = 0; i < m; i++){
         int down = s[i] - 'a';
         int up = (26 - (s[i] - 'a')) % 26;
         costs.emplace_back(up, down);
     }
     sort(costs.begin(), costs.end());
     int pre = 0, suf = 0, i;
     for(i = 0; i < m; i++){
         if(pre + costs[i].first > p)break;
         pre += costs[i].first;
     }
     for(; i < m; i++){
         suf += costs[i].second;
     }
    return {p - pre, q - suf};
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
       int n, p, q; string s;
       cin >> n >> p >> q >> s;
       int l = 0, r = n, idx = 0;
        while (l <= r){
            int m = (l + r) >> 1;
            pair<int, int> t = check(s, p, q, m);
            if(t.first >= 0 and t.second >= 0){
                idx = m;
                l = m + 1;
            }else{
                r = m - 1;
            }
        }
        pair<int, int> t = check(s, p, q, idx);
        for(int i = 0; i < idx; i++){
            s[i] = 'a';
        }
        int extra = t.first, sub = t.second;
        s[idx] = (char) (s[idx] - sub);
        for(int i = idx + 1; i < n; i++){
            int cost  = 26 - (s[i] - 'a');
            if(cost <= extra){
                extra -= cost;
                s[i] = 'a';
            }
        }
        cout << s << '\n';
    }
    return 0;
}
