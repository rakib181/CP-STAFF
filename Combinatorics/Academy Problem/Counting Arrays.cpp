#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e6 + 9, mod = 1e9 + 7;
int f[N], inf[N];

int power(int x, int y){
    int ans = 1;
    while(y){
        if(y & 1) ans = 1LL * ans * x % mod;
        x = 1LL * x * x % mod;
        y >>= 1;
    }
    return ans;
}

void cal(){
    f[0] = 1;
    for(int i = 1; i < N; i++){
        f[i] = 1LL * f[i - 1] * i % mod;
    }
    inf[N - 1] = power(f[N - 1], mod - 2);
    for(int i = N - 2; i >= 0; i--){
        inf[i] = 1LL * inf[i + 1] * (i + 1) % mod;
    }
}

int nCr(int n, int r){
    if(n < 0 or n < r)return 0;
    return 1LL * f[n] * inf[r] % mod * inf[n - r] % mod;
}

vector<int> factorize(int n){
    vector<int> p;
    for(int i = 2; 1LL * i * i <= n; i++){
        while(n % i == 0){
            p.emplace_back(i);
            n /= i;
        }
    }
    if(n > 1)p.emplace_back(n);
    return p;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cal();
    int t;
    cin >> t;
    while(t--){
        int x, y;
        cin >> x >> y;
        vector<int> fact = factorize(x);
        map<int, int> cnt;
        for(auto v : fact){
            cnt[v] += 1;
        }
        int ans = 1;
        for(auto [p, k] : cnt){
            ans = 1LL * ans * nCr(y + k - 1, y - 1) % mod;
        }
        ans = 1LL * ans * power(2, y - 1) % mod;
        cout << ans << '\n';
    }
    return 0;
}