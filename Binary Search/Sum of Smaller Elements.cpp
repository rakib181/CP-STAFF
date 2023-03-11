#include<bits/stdc++.h>
using namespace std;
#define int long long int

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
       int n, q;
       cin >> n >> q;
       vector<pair<int, int>> a(n + 1, {0, 0});
       for(int i = 1; i <= n; i++){
           cin >> a[i].first;
       }
       for(int i = 1; i <= n; i++){
           cin >> a[i].second;
       }
       sort(a.begin() + 1, a.end());
       for(int i = 1; i <= n; i++){
           a[i].second += a[i - 1].second;
       }
        while (q--){
            int x;
            cin >> x;
            int l = 1, r = n, ans = 0;
            while (l <= r){
                int m = (l + r) >> 1;
                if(a[m].first <= x){
                    ans = a[m].second;
                    l = m + 1;
                }else r = m - 1;
            }
            cout << ans << ' ';
        }
        cout << '\n';
    }
    return 0;
}
