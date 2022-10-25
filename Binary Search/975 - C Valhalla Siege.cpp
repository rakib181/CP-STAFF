#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> prefix(n + 2, 0);
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        if(i > 1) prefix[i] += prefix[i - 1] + x;
        else prefix[i] += x;
    }
    int cur = 0;
    while(q--){
        int x;
        cin >> x;
        if(cur + x >= prefix[n])cout << n << '\n', cur = 0;
        else{
            cur += x;
            int l = 1, r = n, ans = 0;
            while(l <= r){
                int mid = (l + r) >> 1;
                if(prefix[mid] <= cur){
                    ans = mid;
                    l = mid + 1;
                }else r = mid - 1;
            }
            cout << n - ans << '\n';
        }
    }
    return 0;
}
