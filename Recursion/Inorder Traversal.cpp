#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    function<void(int)> I_O = [&](int n){
        if(n <= 2){
            if(n == 1 || n == 2)cout << n << ' ';
            return;
        }
        I_O(n - 2);
        cout << n << ' ';
        I_O(n - 1);
     };
     I_O(n);
    return 0;
}
