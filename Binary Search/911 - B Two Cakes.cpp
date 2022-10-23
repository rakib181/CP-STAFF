#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a, b;
    cin >>  n >> a >> b;
    auto possible = [&](int x){
        int xx = min(a, b), yy = max(a, b), cnt = 0;
        while(xx - x >= 0){
            cnt++;
            xx -= x;
        }
        while(yy - x >= 0){
            cnt++;
            yy -= x;
        }
        return cnt >= n;
    };
    int l = 1, r = min(a, b), ans = 0;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(possible(mid)){
            ans = mid;
            l = mid + 1;
        }else r = mid - 1;
    }
    cout << ans << '\n';
    return 0;
}
