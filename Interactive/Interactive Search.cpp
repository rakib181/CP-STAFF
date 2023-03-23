#include<bits/stdc++.h>
using namespace  std;
#define int long long int

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int l = 1, r = n;
    while (l <= r){
        int m = (l + r) >> 1;
        cout << "guess " << m << '\n';
        cout.flush();
        string s;
        cin >> s;
        if(s == "correct" or s == "too many tries"){
            cout << l << '\n';
            cout.flush();
            break;
        }
        if(s == "low"){
            l = m + 1;
        }else r = m - 1;
    }
    return 0;
}
