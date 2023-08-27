#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 30000;

struct node{
    int u, v, w;
    node(int u, int v, int w){
        this -> u = u;
        this -> v = v;
        this -> w = w;
    }
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<node> edges;
    for(int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges.emplace_back(u, v, w);
    }
    vector<int> d(n + 1, inf);
    d[1] = 0;
    for(int i = 1; i < n - 1; i++){
        for(auto x: edges){
            int u = x.u, v = x.v, w = x.w;
            if(d[u] != inf and d[u] + w < d[v]){
                d[v] = d[u] + w;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        cout << d[i] << " \n"[i == n];
    }
    return 0;
}
