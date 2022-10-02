#include <bits/stdc++.h>
using namespace std;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<long long > ar(n);
    for(int i = 0; i < n; i++){
        cin >> ar[i];
    }
    sort(ar.begin(), ar.end());
    long long sum = accumulate(ar.begin(), ar.end(), 0LL);
    int m;
    cin >> m;
    while (m--){
        long long x, y;
        cin >> x >> y;
        long long l1 = 0, r1 = n - 1, ans = 0, coins1 = 0, coins2 = 0;
        while(l1 <= r1){
            long long mid = (l1 + r1) >> 1LL;
            if(ar[mid] >= x){
                ans = ar[mid];
                r1 = mid - 1;
            }else l1 = mid + 1;
        }
        if(ans < x)coins1 += (x - ans);
        if(sum - ans < y){
            coins1 += (y - (sum - ans));
        }
        long long l2 = 0, r2 = n - 1;
        while(l2 <= r2){
            long long mid = (l2 + r2) >> 1LL;
            if(ar[mid] < x){
                ans = ar[mid];
                l2 = mid + 1;
            }else r2 = mid - 1;
        }
        if(ans < x)coins2 += (x - ans);
        if(sum - ans < y){
            coins2 += (y - (sum - ans));
        }
       cout << min<long long > (coins1, coins2) << '\n';
    }
    return 0;
}
