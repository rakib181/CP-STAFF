#include<bits/stdc++.h>
using namespace std;

bool possible(vector<pair<long long, long long>> &ar, int n, long long x){
    for(int i = 0; i < n; i++){
        if(x <= ar[i].first) return false;
        x += ar[i].second;
    }
    return true;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--){
        int n;
        cin >> n;
        vector<pair<long long, long long>> ar(n);
        for(int i = 0; i < n; i++){
            int k, mx = INT_MIN;
            cin >> k;
            for(int j = 0; j < k; j++){
                int x;
                cin >> x;
                mx = max(mx, x - j);
            }
            ar[i] = {mx, k};
        }
        sort(ar.begin(), ar.end());
        long long l = ar[0].first, r = 2 * ar[n - 1].first, ans = 0;
        while(l <= r){
            long long mid = (l + r) >> 1;
            if(possible(ar, n, mid)){
                ans = mid;
                r = mid - 1;
            }else l = mid + 1;
        }
        cout << ans << '\n';
    }
    return 0;
}
