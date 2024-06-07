#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;

vector<vector<int>> prod(vector<vector<int>> &x, vector<vector<int>> &y){
    int row = (int) y.size(), col = (int) y[1].size();
    vector<vector<int>> res(row, vector<int> (col));
    for(int i = 1; i < row; i++){
        for(int j = 1; j < col; j++){
            for(int k = 1; k < row; k++){
                res[i][j] += 1LL * x[i][k] * y[k][j] % mod;
                res[i][j] %= mod;
            }
        }
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    vector<vector<int>> a(7, vector<int> (7));
    vector<vector<int>> b(7, vector<int> (2));
    for(int i = 1; i <= 6; i++){
        a[1][i] = 1;
    }
    for(int i = 2; i <= 6; i++){
        a[i][i - 1] = 1;
    }
    if(n <= 6){
        if(n == 1)cout << "1\n";
        else if(n == 2)cout << "2\n";
        else if(n == 3)cout << "4\n";
        else if(n == 4)cout << "8\n";
        else if(n == 5)cout << "16\n";
        else cout << "32\n";
        return 0;
    }
    b[1][1] = 32;
    b[2][1] = 16;
    b[3][1] = 8;
    b[4][1] = 4;
    b[5][1] = 2;
    b[6][1] = 1;
    n -= 6;
    while(n){
        if(n & 1){
            b = prod(a, b);
        }
        a = prod(a, a);
        n >>= 1;
    }
    cout << b[1][1];
    return 0;
}
