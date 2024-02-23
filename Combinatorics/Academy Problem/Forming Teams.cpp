#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 9, mod = 1000000007;
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

int inv(int x){
    return power(x, mod - 2);
}

void cal(){
    f[0] = 1;
    for(int i = 1; i < N; i++){
        f[i] = 1LL * f[i - 1] * i % mod;
    }
    inf[N - 1] = inv(f[N - 1]);
    for(int i = N - 2; i >= 0; i--){
        inf[i] = 1LL * inf[i + 1] * (i + 1) % mod;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cal();
    int t, cs = 1;
    cin >> t;
    while(t--){
        cout << "Case " << cs++ << ": ";
        int n;
        cin >> n;
        int ans = 0;
        function<int(int)> fun = [&](int k)-> int{
            return 1LL * f[n] * inv(power(f[k], n / k)) % mod * inf[n / k] % mod;
        };
        for(int i = 1; i * i <= n; i++){
            if(n % i == 0){
                ans += fun(i);
                ans %= mod;
                if(n / i != i){
                    ans += fun(n / i);
                    ans %= mod;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}