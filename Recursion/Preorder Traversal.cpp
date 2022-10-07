#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    function<void(int)> P_O = [&](int n){
        if(n <= 2){
            if(n == 1 || n == 2)cout << n << ' ';
            return;
        }
        cout << n << ' ';
        P_O(n - 2);
        P_O(n - 1);
     };
     P_O(n);
    return 0;
}
