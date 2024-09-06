#include<bits/stdc++.h>
using namespace std;

#define long long long

int mod;

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


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, cs = 1;
    cin >> t;
    while(t--){
        cout << "Case " << cs++ << ": ";
        int n, m, a, b;
        cin >> a >> b >> n >> m;
        mod = 1;
        while (m--){
            mod *= 10;
        }
        Mat res;
        res.init(2);
        Mat x;
        x.init(2);
        x.mat[0][0] = 0;
        x.mat[0][1] = 1;
        x.mat[1][0] = 1;
        x.mat[1][1] = 1;
        res.identity();
        int y = n;
        while(y){
            if(y & 1)res = res * x;
            x = x * x;
            y >>= 1;
        }
        cout << (1LL * res.mat[0][0] * a % mod + 1LL * res.mat[0][1] * b % mod) % mod << '\n';
    }
    return 0;
}
