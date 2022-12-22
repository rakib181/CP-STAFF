#include<bits/stdc++.h>
using namespace std;
#define int long long int

const int N = 1e5 + 9;
vector<pair<int, int>> g[N]; vector<int> d(N);
int root_1, root_2, tot;

void DFS(int cur, int par, int weight, int &root){
    if(weight >= tot){
        tot = weight;
        root = cur;
    }
    for(auto x : g[cur]){
        if(x.first != par){
            DFS(x.first, cur, weight + x.second, root);
        }
    }
}

void cal(int cur, int par, int weight){
    d[cur] = max(d[cur], weight);
    for(auto x : g[cur]){
        if(x.first != par){
            cal(x.first, cur, weight + x.second);
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++){
            g[i].clear();
            d[i] = 0;
        }
        for(int i = 0; i < n - 1; i++){
            int u, v, w;
            cin >> u >> v >> w;
            g[u].emplace_back(v, w);
            g[v].emplace_back(u, w);
        }
        tot = 0;
        DFS(1, -1, 0, root_1);
        tot = 0;
        DFS(root_1, -1, 0, root_2);
        cal(root_1, -1, 0);
        cal(root_2, -1, 0);
        for(int i = 1; i <= n; i++){
            cout << d[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
