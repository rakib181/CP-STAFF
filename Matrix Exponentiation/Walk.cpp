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
    int n; ll k;
    cin >> n >> k;
    Mat a;
    a.init(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a.mat[i][j];
        }
    }
    Mat res;
    res.init(n);
    res.identity();
    while(k){
        if(k & 1){
            res = res * a;
        }
        a = a * a;
        k >>= 1;
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            ans += res.mat[i][j];
            ans %= mod;
        }
    }
    cout << ans << '\n';
    return 0;
}
