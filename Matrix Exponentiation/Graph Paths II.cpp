#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const ll inf = 2e18 + 9;

struct Mat{
    int n{};
    vector<vector<ll>> mat;
    void init(int sz){
        this -> n = sz;
        mat.assign(n + 1, vector<ll> (n + 1, inf));
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
                    res.mat[i][j] = min(res.mat[i][j], mat[i][k] + other.mat[k][j]);
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
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        a.mat[u][v] = min(a.mat[u][v], 1LL * w);
    }
    Mat ans;
    ans.init(n);
    k -= 1;
    ans = a;
    while(k){
        if(k & 1){
            ans = ans * a;
        }
        a = a * a;
        k >>= 1;
    }
    cout << ((ans.mat[0][n - 1] == inf) ? -1 : ans.mat[0][n - 1]) << '\n';
    return 0;
}
