#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 105;
vector<int> g[N]; int even;

int DFS(int cur, int par){
    int node = 1;
    for(auto x : g[cur]){
        if(x != par) {
            int tot = DFS(x, cur);
            if(!(tot & 1)) even += 1;
            else node += tot;
        }
    }
    return node;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    even = 0;
    DFS(1, 0);
    cout << even << '\n';
    return 0;
}
