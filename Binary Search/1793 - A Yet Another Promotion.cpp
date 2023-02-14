#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--){
        int a, b, n, m, tot = 0;
        cin >> a >> b >> n >> m;
        int l = 1, r = n;
        while (l <= r){
            int mid = (l + r) / 2;
            if(mid + mid / m >= n){
                tot = mid;
                r = mid - 1;
            }else l = mid + 1;
        }
        int baki = tot % m;
        if(tot % m == 0 and tot + tot / m > n) baki = m;
        cout << min(b * n, a * (tot - baki) + min(a, b) * baki) << '\n';
    }
    return 0;
}
