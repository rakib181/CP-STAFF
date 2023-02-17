#include<bits/stdc++.h>
using namespace std;
#define int long long int

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int gcd(int a, int b){
    if(b == 0)return a;
    return gcd(b, a % b);
}
int bin(int a, int b, int mod){
    int ans = 1;
    while (b){
        if(b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

int pollardRho(int n, int cnt = 0){
    if(n == 1)return 1;
    if(n % 2 == 0)return 2;
    if(cnt == 10)return n;
    int x = (rng() % (n - 2)) + 2;
    int y = x;
    int c = (rng() % (n - 1)) + 1;
    int d = 1;
    while (d == 1){
        x = (bin(x, 2, n) + c + n) % n;
        y = (bin(y, 2, n) + c + n) % n;
        y = (bin(y, 2, n) + c + n) % n;
        d = gcd(abs(y - x), n);
        if(d == n) return pollardRho(n, cnt + 1);
    }
    return d;
}

signed main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   int n;
   cin >> n;
   vector<int> fact;
    while (n != 1){
        int x = pollardRho(n);
        fact.push_back(x);
        n /= x;
    }
    for(auto x : fact){
        cout << x << ' ';
    }
   return 0;
}
