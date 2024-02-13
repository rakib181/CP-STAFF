#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll extendedEuclidean(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = extendedEuclidean(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll x, y;
    cin >> x >> y;
    ll a, b;
    ll gc = extendedEuclidean(y, -x, a, b);
    if(abs(gc) > 2){
        cout << "-1\n";
    }else {
        if(abs(gc) == 1){
            a *= 2, b *= 2;
        }
        cout << a << " " << b << '\n';
    }
    return 0;
}
