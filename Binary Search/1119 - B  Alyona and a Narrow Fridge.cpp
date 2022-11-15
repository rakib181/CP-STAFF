#include<bits/stdc++.h>
using namespace std;

#define int long long int

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, h;
    cin >> n >> h;
    vector<int> height(n);
    for(int i = 0; i < n; i++){
        cin >> height[i];
    }
    auto feasible = [&](int x){
        vector<int> range;
        for(int i = 0; i < x; i++){
            range.push_back(height[i]);
        }
        sort(range.rbegin(), range.rend());
        int cnt = 0;
        for(int i = 0; i < x; i += 2){
           cnt += range[i];
        }
        return cnt <= h;
    };
    int l = 0, r = n + 1, ans = 0;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(feasible(mid)){
            ans = mid;
            l = mid + 1;
        }else r = mid - 1;
    }
    cout << ans << '\n';
    return 0;
}
