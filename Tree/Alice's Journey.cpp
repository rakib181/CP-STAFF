#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 2e5 + 9;
vector<pair<int, int>> g[N]; vector<int> dep(N, 0);

void DFS(int cur, int par){
    for(auto x : g[cur]){
        if(x.first != par) {
            dep[x.first] = dep[cur] + x.second;
            DFS(x.first, cur);
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, tot = 0;
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int u, v, c;
        cin >> u >> v >> c;
        tot += c;
        g[u].emplace_back(v, c);
        g[v].emplace_back(u, c);
    }
    for(int i = 1; i <= n; i++)dep[i] = 0;
    DFS(1, -1);
    int node = 1, mx = 0;
    for(int i = 1; i <= n; i++){
        if(dep[i] > mx){
            node = i;
            mx = dep[i];
        }
    }
    for(int i = 1; i <= n; i++){
        dep[i] = 0;
    }
    DFS(node, -1);
    int d = 0;
    for(int i = 1; i <= n; i++){
        d = max(d, dep[i]);
    }
    cout << 2 * tot - d << '\n';
    return 0;
}
