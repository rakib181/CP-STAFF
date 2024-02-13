#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll nCr(int n, int r){
    ll ans = 1;
    for(int i = n, j = 1; i >= (n - r + 1); i--, j++){
        ans *= i;
        if(j){
            ans /= j;
        }
    }
    return ans;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    ll ans = 0;
    for(int i = 2; i <= n; i++){
        ans += nCr(n, i);
    }
    cout << ans << '\n';
    return 0;
}