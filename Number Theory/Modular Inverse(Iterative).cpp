#include<bits/stdc++.h>
using namespace std;

#define int long long int

int ModInv(int a, int b){
    int M = b, x = 1, y = 0;
    if(b == 1) return 0;
    while(a > 1){
        int  Q = a / M, t = M;
        M = a % M;
        a = t;
        t = y;
        y = x - Q * y;
        x = t;
    }
    if(x < 0){
        x += b;
        return x;
    }
    return x;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b;
    cin >> a >> b;
    if(__gcd(a, b) != 1){
        cout << "Modulo Inverse Doesn,t Exist !" << '\n';
    }else cout << ModInv(a, b) << '\n';
    return 0;
}
