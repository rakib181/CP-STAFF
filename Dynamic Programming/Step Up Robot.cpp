#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 1e5 + 9;

signed main(){
    int tt = 1, cs = 1;
    //cin >> tt;
    while (tt--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        int m;
        cin >> m;
        vector<int> b(N, false);
        for(int i = 0; i < m; i++){
            int x;
            cin >> x;
            b[x] = true;
        }
        int x;
        cin >> x;
        vector<bool> reach(x + 1, false);
        reach[0] = true;
        for(int i = 0; i <= x; i++){
              if(b[i] or !reach[i]){
                  continue;
              }
              for(int j = 0; j < n; j++){
                  if(i + a[j] <= x and !reach[i + a[j]]){
                      reach[i + a[j]] = true;
                  }
              }
        }
        if(reach[x])cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
    return 0;
}
