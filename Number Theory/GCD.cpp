#include<bits/stdc++.h>
using namespace std;

#define int long long int

int gcd(int a, int b){
    while(a){
        if(b == 0)return a;
        int t = b;
        b = a % b;
        a = t;
    }
    return b;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << '\n';
    return 0;
}
