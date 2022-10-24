#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    --k;
    auto possible = [&](int x){
        int cnt = 0;
        for(int i = 1; i <= n; i++){
           if(x > i) cnt += min((x - 1) / i, n);
        }
        return cnt <= k;
    };
    int l = 0, r = n * n + 1, ans = 0;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(possible(mid)){
            ans = mid;
            l = mid + 1;
        }else  r = mid - 1;
    }
    cout << ans << '\n';
    return 0;
}
