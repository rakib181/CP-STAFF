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
        int l = 1, r = n;
        while (l <= r) {
            int m = (l + r) >> 1, cnt = 0;
            cout << "? " << l << ' ' << m << '\n';
            cout.flush();
            for (int i = l; i <= m; i++) {
                int x;
                cin >> x;
                if (x >= l and x <= m) {
                    cnt++;
                }
            }
            if (cnt % 2) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        cout << "! " << l << '\n';
        cout.flush();
    }
    return 0;
}
