#include<bits/stdc++.h>
using namespace std;

int32_t main(){
     ios_base::sync_with_stdio(0);
      cin.tie(0);
      int idx = 1;
      while(1){
        int n, q;
        cin >> n >> q;
        if(n == 0 && q == 0)break;
        cout << "CASE# " << idx++ << ":" << '\n';
        vector<int> ar(n + 1);
        for(int i = 1; i <= n; i++)cin >> ar[i];
        sort(ar.begin(), ar.end());
        while(q--){
        int x;
        cin >> x;
        int l = 1, r = n;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(ar[mid] < x){
                l = mid + 1;
            }else r = mid - 1;
        }
        if(ar[l] == x)cout << x << " found at " <<  l << '\n';
        else cout << x << " not found" << '\n';
         }
      }
      return 0;
}
