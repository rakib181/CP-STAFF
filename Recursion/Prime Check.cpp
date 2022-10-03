#include <bits/stdc++.h>
using namespace std;

bool prime(int  i, int n){
    if(n < 2)return false;
    if(i * i <= n){
        if(n % i == 0)return false;
        return prime(i + 1, n);
    }
    return true;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    cout << prime(2, n) << '\n';
    return 0;
}
