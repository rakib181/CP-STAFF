#include<bits/stdc++.h>
using namespace std;
int n;
void ok(vector<int> ar, int i){
    if(i >= n)return;
    int x = ar[i];
    ok(ar, i + 2);
    cout << x << ' ';
}

int32_t main(){
    ios_base::sync_with_stdio(0);
        cin >> n;
       vector<int> ar(n);
       for(int i = 0; i < n; i++){
           cin >> ar[i];
       }
       ok(ar, 0);
    return 0;
}
