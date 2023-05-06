#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int f(int n, int m){
   if(n == m)return true;
    int l = 1, r = n / 2, ans = -1;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(2 * mid == (n - mid)){
            ans = mid;
            break;
        }
        if(2 * mid > (n - mid))r = mid - 1;
        else l = mid + 1;
    }
    if(ans == -1)return false;
    else {
        if (f(ans, m))return true;
        if (f(n - ans, m))return true;
    }
    return false;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
       int n, m;
       cin >> n >> m;
       if(f(n, m))cout << "YES\n";
       else cout << "NO\n";
    }
    return 0;
}
