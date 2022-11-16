#include<bits/stdc++.h>
using namespace std;
#define int long long int

int inv(int a, int b){
   int M = b, x = 1, y = 0;
   while(a > 1){
       int t = M, Q = a / M;
       M = a % M;
       a = t;
       int tt = y;
       y = x - Q * y;
       x = tt;
   }
   if(x < 0) x += b;
    return x;
}

int Chinese_remainder_theorem(vector<int> &num, vector<int> &rem, int n){
    int prod = 1;
    for(int i = 0; i < n; i++){
        prod *= num[i];
    }
    int result = 0;
    for(int i = 0; i < n; i++){
        int p = prod / num[i];
        result += rem[i] * inv(p, num[i]) * p;
    }
    return result % prod;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> num(n), rem(n);
    for(int i = 0; i < n; i++){
        cin >> num[i];
    }
    for(int i = 0; i < n; i++){
        cin >> rem[i];
    }
    cout << Chinese_remainder_theorem(num, rem, n) << '\n';
    return 0;
}
