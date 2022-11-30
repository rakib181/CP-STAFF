#include <bits/stdc++.h>
using namespace std;

#define int long long int

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int l = 0, r = 1e15, ans = 0;
    while (l <= r){
        int mid = (l + r) >> 1LL;;
        if((((mid + 1) / 2 - 1) + max<long long>((mid / 4) - 1, 0)) >= n){
            ans = mid;
            r = mid - 1;
        }else l = mid + 1;
    }
    cout << ans << '\n';
    return 0;
}
