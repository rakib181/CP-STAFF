#include<bits/stdc++.h>
using namespace std;

long long binpow(long long a, long long d, long long n){
    long long ans = 1;
    while(d){
        if(d & 1) ans = ans * a % n;
        a = a * a % n;
        d >>= 1;
    }
    return ans;
}

bool isPrime(long long n, int iter = 5){
    if(n < 4)return n == 2 || n == 3;

    for(int i = 0; i < iter; i++){
        long long a = 2 + rand() % (n - 3);
        if(binpow(a, n - 1, n) != 1)return false;
    }
    return true;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--) {
        long long n;
        cin >> n;
        if (isPrime(n)) {
            cout << "YES" << '\n';
        } else cout << "NO" << '\n';
    }
    return 0;
}
