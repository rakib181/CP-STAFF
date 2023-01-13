#include<bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int l = 0, r = 0, ans = LONG_LONG_MAX;
    deque<pair<int, int>> v, vv;
    v.emplace_back(0, 0), vv.emplace_back(0, 0);
    while (r < n){
        v.emplace_back(a[r], __gcd(a[r], v.back().second));
        if(__gcd(vv.back().second, v.back().second) == 1){
            ans = min(ans, r - l + 1);
            if((int) vv.size() == 1){
                while ((int) v.size() > 1){
                    vv.emplace_back(v.back().first, __gcd(vv.back().second, v.back().first));
                    v.pop_back();
                }
            }
            while ((int) vv.size() > 1 and __gcd(vv.back().second, v.back().second) == 1){
                vv.pop_back();
                l++;
                if((int) vv.size() == 1){
                    while ((int) v.size() > 1){
                        vv.emplace_back(v.back().first, __gcd(vv.back().second, v.back().first));
                        v.pop_back();
                    }
                }
                if(__gcd(v.back().second, vv.back().second) == 1){
                    ans = min(ans, r - l + 1);
                }
            }
        }
        r++;
    }
    if(ans != LONG_LONG_MAX) cout << ans << '\n';
    else cout << "-1" << '\n';
    return 0;
}
