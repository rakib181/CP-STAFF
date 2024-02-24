#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 65;
ll C[N][N];

void cal(){
    for(int i = 0; i < N; i++){
        C[i][i] = 1;
        for(int j = 0; j < i; j++){
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cal();
    int a, b; ll k;
    cin >> a >> b >> k;
    while(a or b){
        if(k <= C[a + b - 1][b]){
            cout << "a";
            a -= 1;
        }else{
            cout << "b";
            k -= C[a + b - 1][b];
            b -= 1;
        }
    }
    return 0;
}