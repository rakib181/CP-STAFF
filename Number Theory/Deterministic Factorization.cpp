#include<bits/stdc++.h>
using namespace std;
#define  int long long int
array<int, 8> increment = {4, 2, 4, 2, 4, 6, 2, 6};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n; vector<int> factorize;
    for(auto x : {2, 3, 5}){
        while (n % x == 0){
            factorize.push_back(x);
            n /= x;
        }
    }
    int it = 0;
    for(int i = 7; i * i <= n; i = increment[it++]){
        while (n % i == 0){
            factorize.push_back(i);
            n /= i;
        }
        if(it == 8)it = 0;
    }
    if(n > 1)factorize.push_back(n);
    for(auto x : factorize){
        cout << x << ' ';
    }
    return 0;
}

