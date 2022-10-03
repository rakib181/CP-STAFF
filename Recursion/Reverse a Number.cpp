#include <bits/stdc++.h>
using namespace std;

int rev(int n, int c){
   if(n == 0)return c;
   c = c * 10 + (n % 10);
    return rev(n / 10, c);
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    cout << rev(n, 0) << '\n';
    return 0;
}
