#include<iostream>
using namespace std;
#define ll long long

ll nCr(ll n, ll r){
    ll ans = 1;
    r = min(r, n - r);
    for(ll i = 1; i <= r; i++){
        ans = ans * (n - i + 1);
        ans /= i;
    }
    return ans;
}

int main(){
    ll n, m;
    while(cin >> n >> m and !(n == 0 and m == 0)){
        cout << nCr(n + m, m) << '\n';
    }
    return 0;
}