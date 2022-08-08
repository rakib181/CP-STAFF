#include<bits/stdc++.h>
using namespace std;

void ok(int n){
    if(n == 0)return;

    int x = n % 10;
    ok(n / 10);
    cout << x << ' ';
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    int tt;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        if(n == 0){
            cout << "0" << '\n';
            continue;
        }
        ok(n);
        cout << '\n';
    }
    return 0;
}
