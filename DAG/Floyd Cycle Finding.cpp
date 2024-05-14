#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
vector<int> g[N];
int successor[30][N];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
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

    auto floyd_cycle = [&](int node){
        int a = successor[0][node];
        int b = successor[0][successor[0][node]];
        while(a != b){
            a = successor[0][a];
            b = successor[0][successor[0][b]];
        }
        return a;
    };

    auto cycle_length = [&](int node){
        int len = 1;
        int a = node;
        node = successor[0][node];
        while(node != a){
            len += 1;
            node = successor[0][node];
        }
        return len;
    };
    cout << cycle_length(floyd_cycle(4)) << '\n';
    return 0;
}
