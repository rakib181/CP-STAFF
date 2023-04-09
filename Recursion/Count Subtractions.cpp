#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll euclid(ll a, ll b){
    if(b <= 0) return 0;
    ll count = (a - 1) / b;
    a %= b;
    if(a < b)swap(a, b);
    return count + euclid(a, b);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll a, b;
    cin >> a >> b;
    if(a < b)swap(a, b);
    cout << euclid(a, b) << '\n';
    return 0;
}
