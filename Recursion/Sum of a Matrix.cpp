#include<bits/stdc++.h>
using namespace std;

const int N = 105;

int grid1[N][N], grid2[N][N];
void rec(int i, int j, int r, int c){
    if(j == c || i == r)return;
    cout << grid1[i][j] + grid2[i][j] << ' ';
    rec(i, j + 1, r, c);
    if(i < r && j == c - 1) {
        cout << '\n';
        i++;
        rec(i, 0, r, c);
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int r, c;
    cin >> r >> c;
   for(int i = 0; i < r; i++){
       for(int j = 0; j < c; j++){
           cin >> grid1[i][j];
       }
   }
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> grid2[i][j];
        }
    }
    rec(0, 0, r, c);
    return 0;
}
