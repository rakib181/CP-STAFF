#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<char>> &ar, int i, int j, int n, int k){
    if(i < 0 || j < 0 || i >= n || j >= n || ar[i][j] == 'X')return;
    ar[i][j] = 'X';
    dfs(ar, i + k, j, n, k);
    dfs(ar, i - k, j, n, k);
    dfs(ar, i, j + k, n, k);
    dfs(ar, i, j - k, n, k);
    dfs(ar, i - 1, j + 1, n, k);
    dfs(ar, i + 1, j - 1, n, k);
    dfs(ar, i + 1, j + k - 1, n, k);
    dfs(ar, i - 1, j - k + 1, n, k);
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
     int n, k, r, c;
     cin >> n >> k >> r >> c;
     vector<vector<char>> ar(n, vector<char> (n, '.'));
     dfs(ar, r - 1, c - 1, n, k);

     for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << ar[i][j];
        }
        cout << '\n';
     }
    }
    return 0;
}
