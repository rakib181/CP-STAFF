#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b){
    if(a == b)return a;
    if(a <= 0)return b;
    if(b <= 0)return a;
    if(!(a & 1) and !(b & 1)){
        return 2LL * gcd((a >> 1), (b >> 1));
    }
    if(a < b)swap(a, b);
    if((a & 1) and (b & 1)){
        return gcd(((a - b) >> 1), b);
    }
    if(!(b & 1))swap(a, b);
    if(!(a & 1) and (b & 1)){
        return gcd((a >> 1), b);
    }
}
ll lcm(ll a, ll b){
    return a * b / gcd(a, b);
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        ll a, b;
        cin >> a >> b;
        cout << gcd(a, b) << ' ' << lcm(a, b) << '\n';
    }
    return 0;
}
