#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 1e5 + 9;
set<int> g[N];
vector<bool> vis(N);

void BFS(int cur){
    priority_queue<int, vector<int>, greater<>> q;
    q.push(cur);
    vis[1] = true;
    while (!q.empty()){
        int node = q.top();
        cout << node << ' ';
        q.pop();
        for(auto x : g[node]){
            if(!vis[x]){
                q.push(x);
                vis[x] = true;
            }
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].insert(v);
        g[v].insert(u);
    }
    BFS(1);
    return 0;
}
