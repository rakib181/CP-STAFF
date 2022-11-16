#include<bits/stdc++.h>
using namespace std;

#define int long long int

int Extended_Euclidian(int a, int b, int *x, int *y){
    if(a == 0){
        *x = 0;
        *y = 1;
        return b;
    }
    int x1, y1;
    int gcd = Extended_Euclidian(a % b, a, &x1, &y1);

    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b, x, y;
    cin >> a >> b;
    Extended_Euclidian(a, b, &x, &y);
    cout << x << ' ' << y << '\n';
    return 0;
}
