#include<bits/stdc++.h>
using namespace std;

int extendedgcd(int a, int b, int* x, int* y){
     if(a == 0){
         *x = 0, *y = 1;
       return b;
     }
     int x1, y1;
     int gcd = extendedgcd(b % a, a, &x1, &y1);
     *x = y1 - (b/a) * x1;
     *y = x1;
    return gcd;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int a, m, x, y;
    cin >> a >> m;
    int gcd = extendedgcd(a, m, &x, &y);
    if(gcd != 1){
        cout << "Solution Doesn't Exist !" << '\n';
    }else cout <<((x % m) + m) % m << '\n';
    return 0;
}
