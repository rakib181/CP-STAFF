#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 5e5 + 9;
vector<int> g[N], rg[N], order;
vector<bool> vis(N);

void dfs(int cur){
    vis[cur] = true;
    for(auto x : g[cur]){
        if(!vis[x]){
            dfs(x);
        }
    }
    order.push_back(cur);
}

void dfs1(int cur, vector<int> &c){
    vis[cur] = true;
    c.push_back(cur);
    for(auto x : rg[cur]){
        if(!vis[x]){
            dfs1(x, c);
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u++, v++;
        g[u].push_back(v);
        rg[v].push_back(u);
    }
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    reverse(order.begin(), order.end());
    vis.assign(N, false);
    vector<int> cc[n + 2]; int c = 1;
    for(auto  x : order){
        if(!vis[x]){
            vector<int> ccc;
            dfs1(x, ccc);
            cc[c++] = ccc;
        }
    }
    cout << c - 1 << '\n';
    for(int i = 1; i < c; i++){
        cout << (int) cc[i].size() << ' ';
        for(auto  x : cc[i]){
            cout << x - 1 << ' ';
        }
        cout << '\n';
    }
    return 0;
}
