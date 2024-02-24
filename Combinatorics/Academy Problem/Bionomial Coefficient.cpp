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
    int a[n + 1], mx = -1;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    sort(a + 1, a + n + 1);
    int mid = (mx + 1) / 2, d = INT_MAX, y = -1;
    for(int i = 1; i <= n; i++){
        if(abs(mid - a[i]) < d){
            d = abs(mid - a[i]);
            y = a[i];
        }
    }
    cout << mx << ' ' << y<< '\n';
    return 0;
}