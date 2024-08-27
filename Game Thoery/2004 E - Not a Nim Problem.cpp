#include<bits/stdc++.h>
using namespace std;

#define long long long

const int N = 1e7 + 9;
vector<int> spf(N), primes, grundy(N);

void cal(){
    for(int i = 1; i < N; i++)spf[i] = i;
    for(int i = 2; i < N; i += 2)spf[i] = 2;
    primes.emplace_back(2);
    for(int i = 3; i < N; i += 2){
        if(spf[i] == i){
            primes.emplace_back(i);
            for(long j = 1LL * i * i; j < N; j += i){
                spf[j] = min(spf[j], i);
            }
        }
    }
    for(int i = 0; i < (int) primes.size(); i++){
        grundy[primes[i]] = i + 1;
    }
}

int f(int n){
    if(n == 1)return 1;
    n = spf[n];
    if(n == 2)return 0;
    return grundy[n];
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cal();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int ans = 0;
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            ans ^= f(x);
        }
        cout << (ans ? "Alice\n" : "Bob\n");
    }
    return 0;
}
