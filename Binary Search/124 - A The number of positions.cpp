#include <bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a, b;
    cin >> n >> a >> b;
    int l = 0, r = n, ans = 0;
    while (l <= r){
        int mid = (l + r) >> 1;
        if(mid - b <= 1 and mid + a <= n){
            ans = mid;
            l = mid + 1;
        }else r = mid - 1;
    }
    cout << ans << '\n';
    return 0;
}
