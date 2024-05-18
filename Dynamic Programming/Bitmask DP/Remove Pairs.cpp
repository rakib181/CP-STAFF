#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> dp(1 << n);
    vector<vector<int>> g(n, vector<int> (n, 0));
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(a[i] == a[j] or b[i] == b[j]){
                g[i][j] = 1;
            }
        }
    }
    for(int msk = 0; msk < (1 << n); msk++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j)continue;
                if((msk >> i) & 1 and (msk >> j) & 1 and g[i][j] == 1){
                    int new_msk = msk ^ (1 << i);
                    new_msk ^= (1 << j);
                    if(dp[new_msk] == 0)dp[msk] = 1;
                }
            }
        }
    }
    cout << (dp[(1 << n) - 1] ? "Takahashi\n" : "Aoki\n");
    return 0;
}
