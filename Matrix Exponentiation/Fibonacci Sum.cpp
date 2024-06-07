#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1000000007;

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

int fib(int n){
    if(n <= 0)return 0;
    if(n == 1)return 1;
    vector<vector<int>> a(3, vector<int> (3));
    a[1][1] = 1;
    a[1][2] = 1;
    a[2][1] = 1;
    a[2][2] = 0;
    vector<vector<int>> b(3, vector<int> (2));
    b[1][1] = 1;
    b[2][1] = 1;
    while(n){
        if(n & 1){
            b = prod(a, b);
        }
        a = prod(a, a);
        n >>= 1;
    }
    return ((b[1][1] - 1) % mod + mod) % mod;
}

int f(int l, int r){
    return ((fib(r) - fib(l - 1)) % mod + mod) % mod;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        cout << f(n, m) << '\n';
    }
    return 0;
}
