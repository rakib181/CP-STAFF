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
    int t = 1;
    //cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n & 1)cout << "0\n";
        else cout << max(0, (n + 3) / 4 - 1) << '\n';
    }
    return 0;
}