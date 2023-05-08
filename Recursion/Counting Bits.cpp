#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll f(ll n){
    if(n <= 1LL)return n;
    ll sz = 1LL * __lg(n);
    return (sz * (1LL << (sz - 1LL))) + ((n - (1LL << sz)) + 1LL) + f(n - (1LL << sz));
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    cout << f(n);
    return 0;
}
