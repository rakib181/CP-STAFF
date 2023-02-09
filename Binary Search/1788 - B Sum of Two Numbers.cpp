#include<bits/stdc++.h>
using namespace std;
#define int long long int

int fun(int n){
    int s = 0;
    while (n){
        s += (n % 10);
        n /= 10;
    }
    return s;
}

void solve(){
    int n;
    cin >> n;
    int l = 0, r = n;
    while (l <= r){
        int m = (l + r) >> 1;
        int x = fun(m), y = fun(n - m);
        if(abs(x - y) <= 1){
            cout << m << ' ' << n - m << '\n';
            return;
        }
        if(x < y){
            l = m + 1;
        }else r = m - 1;
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--){
        solve();
    }
    return 0;
}
