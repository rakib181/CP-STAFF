#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; string s;
    cin >> n >> s;
    vector<int> cnt(26, 0);
    for(auto x : s){
        cnt[x - 'a'] += 1;
    }
    auto possible = [&](int x){
        int sum = 0;
        if(x == 0)return false;
        for(int i = 0; i < 26; i++){
            if(cnt[i]){
                sum += (int) ceil(cnt[i] / x);
            }
        }
        return sum <= n;
    };
    int l = 0, r = (int) s.size(), ans = r;
    while (l <= r){
        int m = (l + r) >> 1;
        if(possible(m)){
            ans = m;
            r = m - 1;
        }else l = m + 1;
    }
    cout << ans << '\n';
    return 0;
}
