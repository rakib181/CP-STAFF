#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 1e5 + 9;

signed main(){
    int tt = 1, cs = 1;
    //cin >> tt;
    while (tt--){
       int n, m;
       cin >> n >> m;
       vector<int> a[m + 1];
       for(int i = 0; i < m; i++){
           int c;
           cin >> c;
           while (c--){
               int x;
               cin >> x;
               a[i].push_back(x);
           }
       }
       int ans = 0;
       for(int i = 0; i < (1 << m); i++){
           set<int> s;
           for(int j = 0; j < m; j++){
               if((i >> j) & 1){
                   for(auto x : a[j]){
                       s.insert(x);
                   }
               }
           }
           if((int) s.size() == n) ans++;
       }
       cout << ans << '\n';
    }
    return 0;
}
