#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
vector<int> g[N];
int successor[30][N];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        successor[0][u] = v;
    }
    for(int i = 1; i < 30; i++){
        for(int j = 1; j <= n; j++){
            successor[i][j] = successor[i - 1][successor[i - 1][j]];
        }
    }
    auto suc = [&](int node, int k){
        for(int i = 29; i >= 0; i--){
            if((k >> i) & 1){
                node = successor[i][node];
            }
        }
        return node;
    };
    cout << suc(4, 11) << '\n';
    return 0;
}
