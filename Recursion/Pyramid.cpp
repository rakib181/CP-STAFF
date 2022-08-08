#include<bits/stdc++.h>
using namespace std;

void ok(int n, int  j = 1){
    if(n == 0)return;
    for(int i = 0; i < n - 1; i++){
        cout << ' ';
    }
    for(int i = 0; i < j; i++) {
        cout << "*";
    }
    cout << '\n';
    ok(n - 1, j + 2);
}

int32_t main(){
    ios_base::sync_with_stdio(0);
        int n;
        cin >> n;
        ok(n);
    return 0;
}
