#include <bits/stdc++.h>
using namespace std;

#define int long long int

const int N = 20010;
vector<int> g[N];
vector<bool> type(N);
vector<bool> vis(N);

void INIT(){
    for(int i = 0; i < N; i++){
        g[i].clear();
        vis[i] = false;
        type[i] = false;
    }
}

int BFS(int cur){
    int l = 0, v = 0;
    queue<int> q;
    vis[cur] = true;
    q.push(cur);
    type[cur] = true;
    v++;
    while (!q.empty()){
        int node = q.front();
        q.pop();
        for(auto x: g[node]){
            if(!vis[x]){
                q.push(x);
                vis[x] = true;
                if(type[node]){
                   type[x] = false;
                   l++;
                }else{
                    type[x] = true;
                    v++;
                }
            }
        }
    }
    return max(l, v);
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt, idx = 1;
    cin >> tt;
    while (tt--) {
        cout << "Case " << idx++ << ": ";
        INIT();
        int n, mx_node = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
            mx_node = max({mx_node, u, v});
        }
        int sum = 0;
        for(int i = 0; i <= mx_node + 1; i++){
            if(!vis[i] and !g[i].empty()){
                sum += BFS(i);
            }
        }
        cout << sum << '\n';
    }
    return 0;
}
