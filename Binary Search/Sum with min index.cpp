#include<bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
        int n, q;
        cin >> n >> q;
        vector<int> a(n + 1), prefix(n + 1, 0);
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            prefix[i] = prefix[i - 1] + a[i];
        }
        while (q--){
            int i, x;
            cin >> i >> x;
            int l = 1, r = n, ans = -1;
            while (l <= r){
                int mid = (l + r) >> 1;
                if(mid >= i and prefix[mid] - prefix[i - 1] >= x){
                    ans = mid;
                    r = mid - 1;
                }else{
                    l = mid + 1;
                }
            }
            cout << ans << ' ';
        }
        cout << '\n';
    return 0;
}
