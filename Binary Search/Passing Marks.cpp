#include<bits/stdc++.h>
using namespace std;
#define int long long int

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        auto feasible = [&](int xx){
            xx -= 1;
            int cnt = 0;
            for(int i = 0; i < n; i++){
                if(a[i] > xx) cnt += 1;
            }
            return cnt >= x;
        };
        int l = 0, r = *max_element(a.begin(), a.end()), ans = 0;
        while (l <= r){
            int m = (l + r) >> 1;
            if(feasible(m)){
                ans = m - 1;
                l = m + 1;
            }else r = m - 1;
        }
        cout << ans << '\n';
    }
    return 0;
}
