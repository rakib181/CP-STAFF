#include<bits/stdc++.h>
using namespace std;

int32_t main(){
     ios_base::sync_with_stdio(0);
      cin.tie(0); 
        int n;
        cin >> n;
        vector<int> ar(n + 1);
        for(int i = 1; i <= n; i++){
            cin >> ar[i];
        }
        sort(ar.begin(), ar.end());
        int q;
        cin >> q;
        while(q--){
            int x;
            cin >> x;
            int l = 1, r = n, ans = -1;
            while(l <= r){
                int mid = (l + r) >> 1;
                if(ar[mid] == x){
                    ans = mid;
                    l = mid + 1;
                    continue;
                }
                if(ar[mid] < x){
                    ans = mid;
                    l = mid + 1;
                }else r = mid - 1;
            }
           if(ans != -1)cout << ans << '\n';
           else cout << "0" << '\n';
        }    
      return 0;
}
