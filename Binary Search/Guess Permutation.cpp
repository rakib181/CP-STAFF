#include<bits/stdc++.h>
using namespace std;
#define int long long int

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n), ans(n + 1, -1);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        int l = 1, r = n + 1;
        while (l <= r){
            int m = (l + r) >> 1;
            vector<int> p(n + 1); int mx = m, mn = m;
            p[0] = m;
            for(int i = 0; i < n; i++){
                p[i + 1] = p[i] + a[i];
                mx = max(mx, p[i + 1]);
                mn = min(mn, p[i + 1]);
            }
            if(mx > n + 1){
                r = m - 1;
            }else if(mn < 1){
                l = m + 1;
            }else {
                ans = p;
                break;
            }
        }
        if(ans[0] >= 1){
            map<int, int> mp;
            for(int i = 0; i < n + 1; i++){
                mp[ans[i]]++;
            }
            bool ok = true;
            for(auto x : mp){
                if(x.second > 1)ok = false;
            }
            if(mp[-1])ok = false;
            if(ok){
                for(int i = 0; i < n + 1; i++){
                    cout << ans[i] << ' ';
                }
                cout << '\n';
            }else cout << "-1" << '\n';
        }else cout << "-1" << '\n';
    }
    return 0;
}
