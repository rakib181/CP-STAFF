#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 1e5 + 9;
vector<int> g[N], dist(N), prob(N);

void DFS(int cur, int par, int d){
    dist[cur] = d;
    prob[d] += 1;
    for(auto x : g[cur]){
        if(x != par) {
            DFS(x, cur, d + 1);
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    DFS(1, -1, 0);
    while (m--){
        int x;
        cin >> x;
        cout << prob[dist[x]] << '\n';
    }
    return 0;
}
