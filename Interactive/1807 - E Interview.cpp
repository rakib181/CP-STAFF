#include<bits/stdc++.h>
using namespace std;
#define int long long int

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
       int n;
       cin >> n;
       vector<int> a(n + 1, 0);
       for(int i = 1; i <= n; i++){
           cin >> a[i];
           a[i] += a[i - 1];
       }
       int l = 1, r = n, ans = 1;
        while (l <= r){
            int m = (l + r) >> 1;
            cout << "? " << m;
            for(int i = 1; i <= m; i++){
                cout << ' ' << i;
            }
            cout << '\n';
            cout.flush();
            int x;
            cin >> x;
            if(x > a[m]){
                ans = m;
                r = m - 1;
            }else l = m + 1;
        }
        cout << "! " << ans << '\n';
        cout.flush();
    }
    return 0;
}
