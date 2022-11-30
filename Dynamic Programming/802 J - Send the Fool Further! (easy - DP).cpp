#include <bits/stdc++.h>
using namespace std;

const int N = 105;
vector<pair<int, int>> G[N];
vector<int> MX(N, 0);

void DFS(int cur, int par){
    for(auto x : G[cur]){
        if(x.first != par){
            DFS(x.first, cur);
            MX[cur] = max(MX[cur], x.second + MX[x.first]);
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 1; i < n; i++){
        int u, v, wt;
        cin >> u >> v >> wt;
        G[u].emplace_back(v, wt);
        G[v].emplace_back(u, wt);
    }
    DFS(0, -1);
    cout << MX[0] << '\n';
    return 0;
}
