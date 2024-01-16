#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9, SQ = 270;
ll a[N], prefix_sum[SQ + 5][N], prefix_pro[SQ + 5][N];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n, q;
        cin >> n >> q;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        for(int i = 1; i <= SQ; i++){
            for(int j = 1; j <= n; j++){
                if(j <= i){
                    prefix_sum[i][j] = prefix_pro[i][j] = a[j];
                }else{
                    prefix_sum[i][j] = prefix_sum[i][j - i] + a[j];
                    prefix_pro[i][j] = prefix_pro[i][j - i] + a[j] * ((j + i - 1) / i);
                }
            }
        }
        while(q--){
            int s, d, k;
            cin >> s >> d >> k;
            if(d > SQ){
                ll ans = 0;
                for(int i = 1; i <= k; i++){
                    ans += a[s + d * (i - 1)] * i;
                }
                cout << ans << ' ';
            }else{
                int l = s - d, r = s + (k - 1) * d;
                ll ans = prefix_pro[d][r];
                ll res = prefix_sum[d][r];
                if(l >= 0){
                    ans -= prefix_pro[d][l];
                    res -= prefix_sum[d][l];
                }
                cout << ans - res * ((s - 1) / d) << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}
