#include<bits/stdc++.h>
using namespace std;
#define int long long int

const int N = 32000;
vector<bool> is_prime(N, false);
vector<int> primes;
void sieve(){
    is_prime[1] = true;
   for(int i = 4; i < N; i += 2){
       is_prime[i] = true;
   }
   for(int i = 2; i * i < N; i++){
       if(!is_prime[i]){
           for(int j = i * i; j < N; j += i + i){
               is_prime[j] = true;
           }
       }
   }
   for(int  i = 2; i < N; i++){
       if(!is_prime[i])primes.push_back(i);
   }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve();
    int tt;
    cin >> tt;
    while (tt--){
        int n;
        cin >> n;
        vector<int> ar(n); set<int> s; bool ok = false;
        for(int i = 0; i < n; i++)cin >> ar[i];
        vector<int> cnt((int)primes.size());
        for(auto &x : ar) {
            for (int i = 0; i < (int) primes.size(); i++) {
                 if(x % primes[i] == 0){
                     cnt[i]++;
                     while (x % primes[i] == 0) x /= primes[i];
                 }
            }
            if(x > 1){
                if(s.count(x)){
                    ok = true;
                    break;
                }
                s.insert(x);
            }
        }
        if(*max_element(cnt.begin(), cnt.end()) > 1 or ok)cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}
