#include <bits/stdc++.h>
using namespace std;

void rec(int *ar, int *n, int i, int j){
    if(i == *n){
        *n = j;
        return;
    }
    if(!(ar[i] & 1))ar[j++] = ar[i];
    rec(ar, n, i + 1, j);
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int ar[n];
    for(int i = 0; i < n; i++){
        cin >> ar[i];
    }
    rec(ar, &n, 0, 0);
    for(int i = 0; i < n; i++){
        cout << ar[i] << ' ';
    }
    return 0;
}
