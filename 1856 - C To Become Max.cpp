#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int a[n + 1];
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        auto f = [&](int x){
            bool found = false;
            for(int i = 1; i <= n; i++){
                ll need = 0;
                int t_x = x;
                for(int j = i; j <= n; j++){
                    if(a[j] >= t_x){
                        if(need <= k){
                            found = true;
                        }
                        break;
                    }else{
                        need += (t_x - a[j]);
                        t_x -= 1;
                    }
                }
            }
            return found;
        };
        int l = 0, r = 2e9, ans = 0;
        while (l <= r){
            int m = (l + r) >> 1;
            if(f(m)){
                ans = m;
                l = m + 1;
            }else r = m - 1;
        }
        cout << ans << '\n';
    }
    return 0;
}
