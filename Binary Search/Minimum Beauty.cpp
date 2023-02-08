#include<bits/stdc++.h>
using namespace std;
#define int long long int

int bin(int i, int j, int &need, vector<int> &a){
    int idx = j, l = i, r = j;
    while (l <= r){
        int m = (l + r) >> 1;
        if(a[m] < need){
            l = m + 1;
        }else {
            idx = m;
            r = m - 1;
        }
    }
    return idx;
}

int32_t main(){
    int tt;
    cin >> tt;
    while (tt--){
       int n;
       cin >> n;
       vector<int> a(n);
       for(int i = 0; i < n; i++){
           cin >> a[i];
       }
        sort(a.begin(), a.end());
        int ans = LONG_LONG_MAX;
        for(int i = 0; i < n - 2; i++){
            for(int j = i + 1; j < n - 1; j++){
                int req = -a[i] + 2 * a[j];
                int idx = bin(j + 1, n - 1, req, a);
                int cur = a[idx];
                ans = min(ans, abs(cur - req));
                if(idx > j + 1) idx--;
                cur = a[idx];
                ans = min(ans, abs(cur - req));
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
