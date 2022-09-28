#include<bits/stdc++.h>
using namespace std;

bool feasible(vector<long long> &ar, int n, long long x, long long h){
    long long ans = x;
    for(int i = 0; i < n - 1; i++){
       ans += min(x, ar[i + 1] - ar[i]);
    }
    return ans >= h;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--) {
        int n; long long h;
        cin >> n >> h;
        vector<long long> ar(n);
        for (int i = 0; i < n; i++) {
            cin >> ar[i];
        }
        long long l = 1, r = 1e18, ans = 0;
        while (l <= r) {
            long long mid = (l + r) >> 1LL;
            if (feasible(ar, n, mid, h)) {
                ans = mid;
                r = mid - 1;
            } else l = mid + 1;
        }
        cout << ans << '\n';
    }
    return 0;
}
