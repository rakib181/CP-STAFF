#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;

struct Mat{
    int n{};
    vector<vector<int>> mat;
    void init(int sz){
        this -> n = sz;
        mat.assign(n + 1, vector<int> (n + 1, 0));
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
    int n, m, k;
    cin >> n >> m >> k;
    Mat a;
    a.init(n);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        a.mat[u][v] += 1;
    }
    Mat ans;
    ans.init(n);
    ans.identity();
    while(k){
        if(k & 1){
            ans = ans * a;
        }
        a = a * a;
        k >>= 1;
    }
    cout << ans.mat[0][n - 1] << '\n';
    return 0;
}
