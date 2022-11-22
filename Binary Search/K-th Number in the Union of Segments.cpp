#include <bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> ar(n);
    for(int i = 0; i < n; i++){
        cin >> ar[i].first >> ar[i].second;
    }
    auto possible = [&](int x){
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(ar[i].first > x){
                cnt += 0;
            }else if(ar[i].second < x)cnt += (ar[i].second - ar[i].first + 1);
            else cnt += (x - ar[i].first);
        }
        return cnt <= k;
    };
    int l = INT_MIN, r = INT_MAX, ans = 0;
    while (l <= r){
        int mid = (l + r) >> 1;
        if(possible(mid)){
            ans = mid;
            l = mid + 1;
        }else r = mid - 1;
    }
    cout << ans << '\n';
    return 0;
}
