#include<bits/stdc++.h>
using namespace std;

#define long unsigned long long

struct Mat{
    int n{};
    vector<vector<long>> mat;
    void init(int sz){
        this -> n = sz;
        mat.assign(n + 1, vector<long> (n + 1));
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
                    res.mat[i][j] += mat[i][k] * other.mat[k][j];
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
        long p, q, n;
        cin >> p >> q >> n;
        Mat x, res;
        res.init(2);
        x.init(2);
        res.identity();
        x.mat[0][0] = p;
        x.mat[0][1] = -q;
        x.mat[1][0] = 1;
        x.mat[1][1] = 0;
        while(n > 0){
           if(n & 1)res = res * x;
           x = x * x;
           n >>= 1;
        }
        cout << res.mat[1][0] * p + (res.mat[1][1] << 1) << '\n';
    }
    return 0;
}
