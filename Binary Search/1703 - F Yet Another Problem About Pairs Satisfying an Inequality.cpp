#include<bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int ans = 0;
        vector<int> idx;
        for (int i = 1; i <= n; i++) {
            if (a[i] < i) {
                int l = 0, r = (int) idx.size() - 1, sm = (int) idx.size();
                if(!idx.empty()) {
                    while (l <= r) {
                        int mid = (l + r) >> 1;
                        if (idx[mid] >= a[i]) {
                            sm = mid;
                            r = mid - 1;
                        } else {
                            l = mid + 1;
                        }
                    }
                }
                ans += sm;
                idx.push_back(i);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
