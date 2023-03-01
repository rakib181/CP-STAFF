#include<bits/stdc++.h>
using namespace std;
#define int long long int

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--){
       int n, k;
       cin >> n >> k;
       vector<pair<int, int>> a(n);
       for(int i = 0; i < n; i++){
           cin >> a[i].first;
       }
       for(int i = 0; i < n; i++){
           cin >> a[i].second;
       }
       sort(a.begin(), a.end(), [&](pair<int, int> x, pair<int, int> y){
           if(x.first + x.second == y.first + y.second){
               if(x.second == y.second){
                   return x.first < y.first;
               }else return x.second < y.second;
           }
           return (x.first + x.second) < (y.first + y.second);
       });
       auto possible = [&](int take){
           if(take == 0)return true;
           if(take == 1){
               for(int i = 0; i < n; i++){
                   if(a[i].first <= k)return true;
               }
               return false;
           }
           int s = 0, mx1 = -1, mx2 = -1, mx1_idx = -1, mx2_idx = -1;
           for(int i = 0; i < take - 1; i++){
               s += (a[i].first + a[i].second);
               if(a[i].first > mx1){
                   mx1 = a[i].first;
                   mx1_idx = i;
               }
               if(a[i].second > mx2){
                   mx2 = a[i].second;
                   mx2_idx = i;
               }
           }
           for(int i = take - 1; i < n; i++){
               if(s + a[i].first <= k)return true;
               if(mx1 != -1){
                   int t = s;
                   s -= (a[mx1_idx].second);
                   s += (a[i].first + a[i].second);
                   if(s <= k)return true;
                   s = t;
                   s -= (a[mx2_idx].second);
                   s += (a[i].first + a[i].second);
                   if(s <= k)return true;
                   s = t;
               }
           }
           return false;
       };
       int l = 0, r = n, ans = 0;
        while (l <= r){
            int m = (l + r) >> 1;
            if(possible(m)){
                ans = m;
                l = m + 1;
            }else r = m - 1;
        }
        cout << ans << '\n';
    }
    return 0;
}
