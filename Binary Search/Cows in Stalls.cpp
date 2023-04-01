#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 1e5 + 9;
int n, k, a[N];

bool good(int x){
    int cnt = 1, cur_loc = a[1];
    for(int i = 2; i <= n; i++){
        if(a[i] - cur_loc >= x){
            cur_loc = a[i];
            cnt += 1;
        }
        if(cnt == k)return true;
    }
    return false;
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int l = 1, r = *max_element(a + 1, a + n + 1) - *min_element(a + 1, a + n + 1), ans = 0;
    while(l <= r){
        int m = (l + r) >> 1;
        if(good(m)){
            ans = m;
            l = m + 1;
        }else{
            r = m - 1;
        }
    }
    cout << ans << '\n';
    return 0;
}
