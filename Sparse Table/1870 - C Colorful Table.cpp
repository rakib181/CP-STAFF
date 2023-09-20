#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct sparseTable{
    const int inf = (int) 1e9 + 7;
    vector<vector<int>> sp;
    sparseTable(vector<int> &a, int n){
         int lg = 32 - __builtin_clz(n);
         sp.assign(lg + 1, vector<int> (n + 1, -inf));
         for(int i = 0; i < n; i++){
             sp[0][i] = a[i];
         }
         for(int i = 1; i <= lg; i++){
             for(int j = 0; j + (1 << (i - 1)) <= n; j++){
                 sp[i][j] = max(sp[i - 1][j], sp[i - 1][j + (1 << (i - 1))]);
             }
         }
    }
    int query(int l, int r){
        int lg = __lg(r - l + 1);
        return max(sp[lg][l], sp[lg][r - (1 << (lg)) + 1]);
    }
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> a(n), used(k, 0), ans(k, 0);
        for(int i = 0; i < n; i++){
            cin >> a[i];
            a[i] -= 1;
            used[a[i]] = 1;
        }
        sparseTable sp(a, n);
        for(int i = 0; i < k; i++){
            if(!used[i])continue;
            int L, R;
            {
                int l = 0, r = n - 1, idx = 0;
                while(l <= r){
                    int m = (l + r) >> 1;
                    if(sp.query(0, m) >= i){
                        idx = m;
                        r = m - 1;
                    }else {
                        l = m + 1;
                    }
                }
                L = idx;
            }
            {
                int l = 0, r = n - 1, idx = 0;
                while(l <= r){
                    int m = (l + r) >> 1;
                    if(sp.query(m, n - 1) >= i){
                        idx = m;
                        l = m + 1;
                    }else{
                        r = m - 1;
                    }
                }
                R = idx;
            }
            ans[i] = 2 * (R - L + 1);
        }
        for(int i = 0; i < k; i++){
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
