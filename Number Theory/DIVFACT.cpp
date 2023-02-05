#include<bits/stdc++.h>
using namespace std;
#define  int long long int
const int N = 5e4 + 9, MOD = 1e9 + 7;
vector<int> primes;
bool is_composite[N];

void sieve () {
    std::fill (is_composite, is_composite + N, false);
    for (int i = 2; i < N; ++i) {
        if (!is_composite[i]) primes.push_back (i);
        for (int j = 0; j < primes.size () && i * primes[j] < N; ++j) {
            is_composite[i * primes[j]] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve();
    int tt;
    cin >> tt;
    while (tt--){
        int n, ans = 1;
        cin >> n;
        for(int i = 0; i < (int) primes.size() and primes[i] <= n; i++){
            int tp = 1, cnt = 0;
            while ((tp * primes[i]) <= n){
                tp *= primes[i];
                cnt += (n / tp);
            }
            ans = ans * (cnt + 1) % MOD;
        }
        cout << ans << '\n';
    }
    return 0;
}

