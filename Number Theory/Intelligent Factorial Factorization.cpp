#include<bits/stdc++.h>
using namespace std;
#define  int long long int

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt, cs = 1;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        cout << "Case " << cs++ << ": " <<  n << " = ";
        vector<int> cnt(n + 1, 0);
        for (int i = 2; i <= n; i++) {
            int tmp = i;
            for (int j = 2; j * j <= i; j++) {
                while (tmp % j == 0) {
                    cnt[j] += 1;
                    tmp /= j;
                }
            }
            if (tmp > 1) cnt[tmp] += 1;
        }
        bool ok = false;
        for(int i = 1; i <= n; i++){
             if(cnt[i]){
                 if(ok) cout << "* " << i << " (" << cnt[i] << ") ";
                 else cout << i << " (" << cnt[i] << ")" << ' ';
                 ok = true;
             }
        }
        cout << '\n';
    }
    return 0;
}

