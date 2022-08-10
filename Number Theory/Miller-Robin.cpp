#include<bits/stdc++.h>
using namespace std;

long long binpow(long long a, long long d, int n){
    long long ans = 1;
    while(d){
        if(d & 1) ans = ans * a % n;
        a = a * a % n;
        d >>= 1;
    }
    return ans;
}

bool composite(long long a, long long d, int s, int n){
    long long x = binpow(a, d, n);
    if(x == 1 || x == n - 1)return false;

    for(int i = 1; i < s; i++){
        x = x * x % n;
        if(x == n - 1)return false;
    }
    return true;
}

bool millerrobin(int n, int iter = 5){
    if(n < 4){
        return n == 2 || n == 3;
    }
    long long s = 0, d = n - 1;
    while(!(d & 1)){
        d >>= 1;
        s++;
    }
    for(int i = 0; i < iter; i++){
        int a = 2 + rand() % (n - 3);
        if(composite(a, d, s, n)){
            return false;
        }
    }
    return true;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin >> n;
    if(millerrobin(n)){
        cout << "Prime !" << '\n';
    }else cout << "Not Prime !" <<'\n';
    return 0;
}
