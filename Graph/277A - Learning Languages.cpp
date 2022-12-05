#include<bits/stdc++.h>
using namespace std;

const int N = 205;
set<int> g[N];
vector<bool> vis(N);

void DFS(int cur){
    vis[cur] = true;
    for(auto x : g[cur]){
        if(!vis[x]){
            DFS(x);
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, ow = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        ow += x;
        for(int j = 0; j < x; j++){
            int v;
            cin >> v;
            g[i + 1].insert(n + v);
            g[n + v].insert(i + 1);
        }
    }
    int cc = 0;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            DFS(i);
            cc++;
        }
    }
    if(!ow)cout << n << '\n';
    else cout << cc - 1 << '\n';
    return 0;
}
