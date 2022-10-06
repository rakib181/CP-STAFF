#include <bits/stdc++.h>
using  namespace std;

bool possible(vector<long long> &ar, int n, long long x, int k){
    long long sum = 0LL;
    for(int i = 0; i < n; i++){
        if(ar[i] >= x) sum += x;
        else sum += ar[i];
        if((sum / x) >= k)return true;
    }
    return false;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int k, n;
    cin >> k >> n;
    vector<long long> ar(n);
    for(int i = 0; i < n; i++){
        cin >> ar[i];
    }
    long long l = 0, r = accumulate(ar.begin(), ar.end(), 0LL), ans = 0;
    while(l <= r){
        long long mid = (l + r) >> 1LL;
        if(possible(ar, n, mid, k)){
            ans = mid;
            l = mid + 1;
        }else r = mid - 1;
    }
    cout << ans << '\n';
    return 0;
}
