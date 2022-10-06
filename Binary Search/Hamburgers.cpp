#include <bits/stdc++.h>
using  namespace std;

bool possible(vector<pair<long long, long long>> &ingredient, long long x, map<char, int> &mp, long long tot_money){
    long long bread = mp['B'] * x, sausage = mp['S'] * x, cheese = mp['C'] * x;
    vector<long long> ingre = {bread, sausage, cheese};
    for(int i = 0; i < 3; i++){
        long long extra_need = ingre[i] - ingredient[i].first;
        if(extra_need > 0) tot_money -= extra_need * ingredient[i].second;
    }
    return tot_money >= 0;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; vector<pair<long long, long long>> ingredient(4);
    cin >> s; map<char, int> mp;
    for(auto x : s){
        mp[x]++;
    }
    for(int i = 0; i < 3; i++){
        cin >> ingredient[i].first;
    }
    for(int i = 0; i < 3; i++){
        cin >> ingredient[i].second;
    }
    long long tot_money;
    cin >> tot_money;
    long long l = 0, r = 1e15, ans = 0;
    while(l <= r){
        long long mid = (l + r) >> 1LL;
        if(possible(ingredient, mid, mp, tot_money)){
            ans = mid;
            l = mid + 1;
        }else r = mid - 1;
    }
    cout << ans << '\n';
    return 0;
}
