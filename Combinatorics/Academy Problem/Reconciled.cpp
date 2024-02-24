#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 9, mod = 1e9 + 7;
int f[N];

void cal(){
    f[0] = 1;
    for(int i = 1; i < N; i++){
        f[i] = 1LL * f[i - 1] * i % mod;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cal();
    int n, m;
    cin >> n >> m;
    if(n < m)swap(n, m);
    if(n - m > 1){
        cout << "0\n";
        return 0;
    }
    if(n != m){
        cout << 1LL * f[n] * f[m] % mod;
    }else{
        cout << 2LL * f[n] * f[m] % mod;
    }
    return 0;
}