#include <bits/stdc++.h>
using namespace std;
#define int long long int


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, c, d;
        cin >> n >> c >> d;
        vector<int> ar(n + 1), prefix(n + 2, 0);
        for(int i = 0; i < n; i++){
            cin >> ar[i];
        }
        sort(ar.rbegin(), ar.rend());
        prefix[1] = ar[0];
        for(int i = 2; i <= n; i++){
           prefix[i] = prefix[i - 1] + ar[i - 1];
        }
        auto possible = [&](int x){
            if(x <= n)return prefix[x];
            return prefix[n];
        };
        int l = 1, r = d + 1, ans = -1;
        while (l <= r){
            int mid = (l + r) >> 1;
            if(d / mid * possible(mid) + possible(d % mid) >= c){
                ans = mid;
                l = mid + 1;
            }else r = mid  - 1;
        }
        if(ans == -1)cout << "Impossible" << '\n';
        else if(ans == d + 1)cout << "Infinity" << '\n';
        else cout << ans - 1 << '\n';
    }
    return 0;
}
