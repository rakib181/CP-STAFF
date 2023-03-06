#include<bits/stdc++.h>
using namespace std;
#define int long long int

const int N = 2005;
vector<int> g[N];
vector<bool> vis;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        vis.assign(n + 1, false);
        queue<int> q;
        q.push(i);
        vis[i] = true;
        while (!q.empty()){
            int node = q.front();
            q.pop();
            for(auto x : g[node]){
                if(!vis[x]){
                    q.push(x);
                    vis[x] = true;
                    ans += 1;
                }
            }
        }
    }
    cout << ans - m << '\n';
    return 0;
}
