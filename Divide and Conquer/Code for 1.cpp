#include<bits/stdc++.h>
using namespace std;

const int inf = 1e9 + 7;
#define long long long

map<long, long> nz, len;


void precal(long n){
    if(n < 2){
        nz[n] = n;
        len[n] = 1;
    }else {
        precal(n / 2);
        nz[n] = nz[n / 2] * 2 + (n & 1);
        len[n] = len[n / 2] * 2 + 1;
    }
}

long cal(long n, long r){
    if(r <= 0)return 0;
    if(r >= len[n]){
        return nz[n];
    }
    return cal(n / 2, r) + (r > len[n / 2] ? (n & 1) : 0) + cal(n / 2, r - len[n / 2] - 1);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long n, l, r;
    cin >> n >> l >> r;
    precal(n);
    cout << cal(n, r) - cal(n, l - 1) << '\n';
    return 0;
}
