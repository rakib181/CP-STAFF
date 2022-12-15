#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 1e7 + 5;
vector<int> cnt(N, 0);
vector<bool> is_prime(N, false);

void sieve(){
   is_prime[0] = is_prime[1] = true;
    for(int i = 2; i < N; i++){
        if(!is_prime[i]){
            for(int j = 2 * i; j < N; j += i){
                is_prime[j] = true;
                cnt[i] += cnt[j];
            }
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        cnt[x]++;
    }
    sieve();
    for(int i = 1; i < N; i++){
        if(is_prime[i])cnt[i] = 0;
    }
    for(int i = 1; i < N; i++){
        cnt[i] += cnt[i - 1];
    }
    int q;
    cin >> q;
    while (q--){
        int l, r;
        cin >> l >> r;
        if(l > (int) 1e7)l = 1e7;
        if(r > (int) 1e7)r = 1e7;
        cout << cnt[r] - cnt[l - 1] << '\n';
    }
    return 0;
}
