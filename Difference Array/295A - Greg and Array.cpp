#include<bits/stdc++.h>
using namespace std;
#define int long long int

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
       int n, m, k;
       cin >> n >> m >> k;
       vector<int> a(n + 1), dif(n + 2, 0);
       for(int i = 1; i <= n; i++){
           cin >> a[i];
       }
       vector<pair<int, int>> ops(m + 2, {0, 0});
       vector<int> val(m + 2, 0);
       for(int i = 1; i <= m; i++){
           cin >> ops[i].first >> ops[i].second >> val[i];
       }
       vector<int> ops_count(m + 2, 0);
      while (k--){
        int l, r;
        cin >> l >> r;
        ops_count[l] += 1;
        ops_count[r + 1] -= 1;
      }
      for(int i = 1; i <= m; i++){
          ops_count[i] += ops_count[i - 1];
      }
      for(int i = 1; i <= m; i++){
          if(ops_count[i]){
              int l = ops[i].first, r = ops[i].second;
              dif[l] += (ops_count[i] * val[i]);
              dif[r + 1] -= (ops_count[i] * val[i]);
          }
      }
      for(int i = 1; i <= n; i++){
          dif[i] += dif[i - 1];
          a[i] += dif[i];
      }
      for(int i = 1; i <= n; i++){
          cout << a[i] << ' ';
      }
      return 0;
}
