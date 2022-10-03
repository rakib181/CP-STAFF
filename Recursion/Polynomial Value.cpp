#include <bits/stdc++.h>
using namespace std;

int rec(int i, int x, int n){
    if(n == 0)return 1;
    if(i < n){
        return (int) pow(x, i) + rec(i + 1, x, n);
    }
    return 0;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int x, n;
    cin >> x >> n;
    cout << rec(0, x, n);
    return 0;
}
