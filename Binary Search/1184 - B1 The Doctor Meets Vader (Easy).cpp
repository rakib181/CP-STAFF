#include<bits/stdc++.h>
using namespace std;

#define int long long int


int32_t main(){
     ios_base::sync_with_stdio(false);
     cin.tie(nullptr);
     int n , m;
      cin >> n >> m;
      vector<int> ar(n);
      vector<pair<int, int>> query(m);
      for(int i = 0; i < n; i++){
          cin >> ar[i];
      }
      for(int  i = 0; i < m; i++){
          cin >> query[i].first >> query[i].second;
      }
      sort(query.begin(), query.end());
      vector<pair<int, int>> prefix(m, {0, 0});
      prefix[0].first = query[0].first;
      prefix[0].second = query[0].second;
      for(int i = 1; i < m; i++){
          prefix[i].first = max(prefix[i - 1].first , query[i].first);
          prefix[i].second += prefix[i - 1].second + query[i].second;
      }
      for(int i = 0; i < n; i++){
          int l = 0, r = m - 1, ans = 0;
          while(l <= r){
              int mid = (l + r) >> 1LL;
              if(prefix[mid].first <= ar[i]){
                  ans = prefix[mid].second;
                  l = mid + 1;
              }else r = mid - 1;
          }
          cout << ans << ' ';
      }
     return 0;
}
