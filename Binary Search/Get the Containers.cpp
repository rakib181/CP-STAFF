#include<bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt, cs = 1;
    cin >> tt;
    while (tt--) {
        cout << "Case " << cs++ << ":" << ' ';
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        auto possible = [&] (int x){
            int cnt = 1;
            int s = 0;
            for(int i = 0; i < n; i++){
                if(a[i] > x)return false;
                 if(s + a[i] > x){
                     cnt++;
                     s = 0;
                 }
                 s += a[i];
            }
            return cnt <= m;
        };
        int l = 1, r = 1e12, ans = 1;
        while (l <= r){
            int mid = (l + r) >> 1;
            if(possible(mid)){
                ans = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
