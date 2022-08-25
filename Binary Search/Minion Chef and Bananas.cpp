#include <bits/stdc++.h>
using namespace std;

bool good(vector<int> &ar, int n, int h, long long x){
    long long tot = 0;
    for(int i = 0; i < n; i++){
        tot += (ar[i] / x);
        if(ar[i] % x) tot++;
    }
    return tot <= h;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--) {
        int n, h;
        cin >> n >> h;
        vector<int> ar(n);
        for (int i = 0; i < n; i++) {
            cin >> ar[i];
        }
        long long l = 1, r = accumulate(ar.begin(), ar.end(), 0LL), ans = 0;
        while (l <= r) {
            long long mid = (l + r) >> 1;
            if (good(ar, n, h, mid)) {
                ans = mid;
                r = mid - 1;
            } else l = mid + 1;
        }
        cout << ans << '\n';
    }
    return 0;
}
