#include <bits/stdc++.h>
using namespace std;

bool good(vector<int> &ar, int n, long long limit, int m){
    long long cnt = 1, sum = 0;
    for(int i = 0; i < n; i++){
        if(ar[i] > limit)return false;

        if(sum + ar[i] > limit){
            cnt++;
            sum = ar[i];
        }else{
            sum += ar[i];
        }
    }
    return cnt <= m;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> ar(n);
    for(int i = 0; i < n; i++)cin >> ar[i];

    long long l = *max_element(ar.begin(), ar.end()), r = accumulate(ar.begin(), ar.end(), 0LL), ans = r;

    while(l <= r){
        long long mid = (l + r) >> 1;
        if(good(ar, n, mid, m)){
            ans = mid;
            r = mid - 1;
        }else l = mid + 1;
    }
   cout << ans << '\n';
    return 0;
}
