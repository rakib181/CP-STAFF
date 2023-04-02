#include<bits/stdc++.h>
using namespace std;

bool intersect(int a, int b, int c, int k){
    return 1LL * (b - k) * (b - k) >= 4LL * a * c;
}

 signed main(){
     ios_base::sync_with_stdio(false);
     cin.tie(nullptr);
     int tt;
     cin >> tt;
     while (tt--){
        int n, m;
        cin >> n >> m;
        int k[n + 1];
        for(int i = 1; i <= n; i++){
            cin >> k[i];
        }
        sort(k + 1, k + n + 1);
         while (m--) {
             int a, b, c;
             cin >> a >> b >> c; bool found = false;
             int x = (int) (lower_bound(k + 1, k + n + 1, b) - k);
             for(int i = max(1, x - 10); i <= min(n, x + 10); i++){
                  if(!intersect(a, b, c, k[i])){
                       cout << "YES" << '\n' << k[i] << '\n';
                       found = true;
                       break;
                  }
             }
             if(!found)cout << "NO" << '\n';
         }
     }
     return 0;
}
