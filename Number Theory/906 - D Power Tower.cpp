#include<bits/stdc++.h>
using namespace std;
#define long long long int
const int N = 1e5 + 9;
vector<int> a(N);

map<int, int> dp;

int phi(int n){
    if(dp.count(n))return dp[n];
    int v = n;
    int cnt = n;
    for(int p = 2; 1LL * p * p <= n; p++){
        if(n % p == 0){
            while(n % p == 0) n /= p;
            cnt = cnt / p * (p - 1);
        }
    }
    if(n > 1)cnt = cnt / n * (n - 1);
    return dp[v] = cnt;
}

int modulu(long x, int mod){
    if(x < mod)return int(x);
    return int(x % mod + mod);
}

int power(int x, int y, int mod){
    int ans = modulu(1, mod);
    while(y){
        if(y & 1) ans = modulu(1LL * ans * x, mod);
        x = modulu(1LL * x * x, mod);
        y >>= 1;
    }
    return ans;
}

int f(int l, int r, int m){
    if(l == r){
        return modulu(a[l], m);
    }
    if(m == 1){
        return 1;
    }
    return power(a[l], f(l + 1, r,phi(m)), m);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)cin >> a[i];
    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        cout << f(l, r, m) % m << '\n';
    }
    return 0;
}
