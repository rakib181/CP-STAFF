#include<bits/stdc++.h>
using namespace std;

#define int long long int


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--) {
        int n, q;
        cin >> n >> q;
        vector<int> ar(n);
        for(int i = 0; i < n; i++){
            cin >> ar[i];
        }
        vector<pair<int, int>> prefix(n + 1, {0, 0});
        prefix[0].first = ar[0];
        prefix[0].second = ar[0];
        for(int i = 1; i < n; i++){
            prefix[i].first = max(prefix[i - 1].first, ar[i]);
           prefix[i].second += prefix[i - 1].second + ar[i];
        }
        for(int i = 0; i < q; i++){
            int x;
            cin >> x;
            int l = 0, r = n - 1, ans = 0;
            while(l <= r){
                int mid = (l + r) >> 1;
                if(prefix[mid].first <= x){
                    ans = prefix[mid].second;
                    l = mid + 1;
                }else r = mid - 1;
            }
            cout << ans << ' ';
        }
        cout << '\n';
    }
    return 0;
}
