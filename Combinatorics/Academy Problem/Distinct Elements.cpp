#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while(t--){
       int n;
       cin >> n;
       map<int, int> cnt;
       for(int i = 1; i <= n; i++){
           int x;
           cin >> x;
           cnt[x] += 1;
       }
       ll ans = 1;
       for(auto [x, y] : cnt){
           ans *= (y + 1);
           ans %= mod;
       }
       cout << ans - 1 << '\n';
    }
    return 0;
}