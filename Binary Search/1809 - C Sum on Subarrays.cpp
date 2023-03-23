#include<bits/stdc++.h>
using namespace  std;
#define int long long int

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--){
        int n, k;
        cin >> n >> k;
        int l = 0, r = n, x = 0;
        while (l <= r){
            int m = (l + r) >> 1;
            if((m * (m + 1)) / 2 <= k){
                x = m;
                l = m + 1;
            }else r = m - 1;
        }
        int ex = k - (x * (x + 1)) / 2;
        for(int i = 1; i <= n; i++){
            if(i == x + 1){
                if(!ex){
                    cout << "-1000" << ' ';
                }else{
                    cout << -(2 * (x - ex + 1) - 1) << ' ';
                }
            }else if(i <= x) cout << "2" << ' ';
            else cout << "-1000" << ' ';
        }
        cout << '\n';
    }
    return 0;
}
