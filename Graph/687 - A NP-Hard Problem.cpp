#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 1e5 + 9;
vector<int> g[N], col(N, -1), disjoint[3];
vector<bool> vis(N);

bool DFS(int cur, int c){
    vis[cur] = true;
    col[cur] = c;
    if(c == 1){
        disjoint[1].push_back(cur);
    }else disjoint[2].push_back(cur);
    for(auto x : g[cur]){
        if(!vis[x]){
           bool sub = DFS(x, 1 - c);
            if(sub)return true;
        }else if(col[cur] == col[x]){
            return true;
        }
    }
    return false;
}

int32_t main(){
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
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            if(g[i].empty())continue;
            if(DFS(i, 0)){
                cout << "-1" << '\n';
                return 0;
            }
        }
    }
    cout << (int) disjoint[1].size() << '\n';
    for(auto  x: disjoint[1]){
        cout << x << ' ';
    }
    cout << '\n' << (int) disjoint[2].size() << '\n';
    for(auto  x: disjoint[2]){
        cout << x << ' ';
    }
    return 0;
}
