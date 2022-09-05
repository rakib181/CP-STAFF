#include<bits/stdc++.h>
using namespace std;

bool compare(int x, int y){
    return x > y;
}

int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while(tt--){
    int n, q;
    cin >> n >> q;
    vector<int> ar(n); vector<long long> prefix(n + 1, 0);
    for(int i = 0; i < n; i++){
        cin >> ar[i];
    }
   sort(ar.begin(), ar.end(), compare);
   for(int i = 0; i < n; i++){
    prefix[i] += ar[i];
    if(i)prefix[i] += prefix[i - 1];
   }
    while(q--){
        int k;
        cin >> k;
        long long l = 1, r = n, ans = -1;
        while(l <= r){
            long long mid = (l + r) >> 1;
            if(prefix[mid - 1] >= k){
                ans = mid;
                r = mid - 1;
            }else l = mid + 1;
        }
      if(ans > n)cout << "-1" << '\n';
      else cout << ans << '\n';
    }
  }
  return 0;
}
