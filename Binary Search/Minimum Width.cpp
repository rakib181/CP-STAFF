#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
int n, k, a[N];

bool f(ll x){
    ll s = 0; int cnt  = 1;
    for(int i = 1; i <= n; i++){
        if(a[i] > x)return false;
        if(s + a[i] > x){
            cnt += 1;
            s = a[i] + 1;
        }else{
            s += (a[i] + 1);
        }
    }
    return cnt <= k;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    ll l = 0, r = 1e15, ans = 0;
    while(l <= r){
        ll m = (l + r) >> 1;
        if(f(m)){
            ans = m;
            r = m - 1;
        }else l = m + 1;
    }
    cout << ans << '\n';
    return 0;
}
