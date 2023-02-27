#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--){
        int n;
        cin >> n;
        vector<int> prefix_sum(n, 0), prefix_xor(n, 0);
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
           if(i) {
               prefix_sum[i] = prefix_sum[i - 1] + x;
               prefix_xor[i] = prefix_xor[i - 1] ^ x;
           }else{
               prefix_sum[i] = x;
               prefix_xor[i] = x;
           }
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            int l = i, r = n - 1, j = i;
            while (l <= r){
                int m = (l + r) >> 1;
                int x = prefix_sum[m] - (i == 0 ? 0 :prefix_sum[i - 1]), y = prefix_xor[m] ^ (i == 0 ? 0 : prefix_xor[i - 1]);
                if(x == y){
                    j = m;
                    l = m + 1;
                }else r = m - 1;
            }
            ans += (j - i + 1);
        }
        cout << ans << '\n';
    }
    return 0;
}
