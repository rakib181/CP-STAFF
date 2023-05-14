#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 105;
vector<int> g[N];
int ind[N];


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    while(cin >> n >> m and !(n == 0 and m == 0)) {
        for(int i = 1; i <= n; i++){
            g[i].clear();
            ind[i] = 0;
        }
        for(int i = 1; i <= m; i++){
            int u, v;
            cin >> u >> v;
            g[u].emplace_back(v);
            ind[v] += 1;
        }
        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (!ind[i])q.push(i);
        }
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << ' ';
            for (auto x: g[node]) {
                if (--ind[x] == 0) {
                    q.push(x);
                }
            }
        }
        cout << '\n';
    }
    return 0;
}

//DFS
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 105;
vector<int> g[N];
bool vis[N];
vector<int> order;

void dfs(int u){
    vis[u] = true;
    for(auto x : g[u]){
        if(!vis[x]){
            dfs(x);
        }
    }
    order.emplace_back(u);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    while(cin >> n >> m and !(n == 0 and m == 0)) {
        order.clear();
        for(int i = 1; i <= n; i++){
            g[i].clear();
            vis[i] = false;
        }
        for(int i = 1; i <= m; i++){
            int u, v;
            cin >> u >> v;
            g[u].emplace_back(v);
        }
        for(int i = 1; i <= n; i++){
            if(!vis[i]){
                dfs(i);
            }
        }
        reverse(order.begin(), order.end());
        for(auto  x: order){
            cout << x << ' ';
        }
        cout << '\n';
    }
    return 0;
}
