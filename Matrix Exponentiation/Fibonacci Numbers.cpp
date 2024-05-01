#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;

struct Mat{
    int n{};
    vector<vector<int>> mat;
    void init(int sz){
        this -> n = sz;
        mat.assign(n + 1, vector<int> (n + 1));
    }
    void identity(){
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= n; j++){
                mat[i][i] = 1;
            }
        }
    }
    Mat operator *(Mat &other) const{
        Mat res;
        res.init(n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                for(int k = 0; k < n; k++){
                    res.mat[i][j] += 1LL * mat[i][k] * other.mat[k][j] % mod;
                    res.mat[i][j] %= mod;
                }
            }
        }
        return res;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    if(n <= 2){
        if(n == 0){
            cout << 0 << '\n';
        }else if(n == 1){
            cout << 1 << '\n';
        }else {
            cout << 1 << '\n';
        }
        return 0;
    }
    Mat a;
    a.init(2);
    a.mat[0][0] = 1;
    a.mat[0][1] = 1;
    a.mat[1][0] = 1;
    a.mat[1][1] = 0;
    n -= 2;
    Mat ans;
    ans.init(2);
    ans.identity();
    while(n){
        if(n & 1)ans = ans * a;
        a = a * a;
        n >>= 1;
    }
    vector<vector<int>> x(2, vector<int> (1, 0));
    x[0][0] = 1;
    x[1][0] = 1;
    int res = 0;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 1; j++){
            for(int k = 0; k < 1; k++){
                res += 1LL * ans.mat[i][k] * x[k][j] % mod;
                res %= mod;
            }
        }
    }
    cout << res << '\n';
    return 0;
}
