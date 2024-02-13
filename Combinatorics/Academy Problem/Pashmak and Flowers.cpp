#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    int mx = 0, mn = INT_MAX;
    map<int, int> cnt;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        cnt[x] += 1;
        mx = max(mx, x);
        mn = min(mn, x);
    }
    if(mx == mn){
        cout << mx - mn << ' ' <<  1LL * cnt[mx] * (cnt[mx] - 1) / 2 << '\n';
    }else{
        cout << mx - mn << ' ' <<  1LL * cnt[mx] * cnt[mn] << '\n';
    }
    return 0;
}