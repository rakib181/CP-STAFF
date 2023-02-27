#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 1e5 + 9;
vector<int> g[N], lvl(N), node;
vector<bool>  vis(N);

void DFS(int cur, int c){
    node.push_back(cur);
    vis[cur] = true;
    lvl[cur] = c;
    for(auto x : g[cur]){
        if(!vis[x]){
            DFS(x, c + 1);
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> w(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> w[i];
    }
    vector<pair<int, int>> edge;
    for(int i = 1; i <= n - 1; i++){
        int u, v;
        cin >> u >> v;
        edge.emplace_back(u, v);
    }
    int l = 1, r = N, ans = -1;
    while (l <= r){
        int m = (l + r) >> 1;
        for(int i = 1; i <= n; i++){
            g[i].clear();
            lvl[i] = 0;
            vis[i] = false;
        }
        for(auto x : edge){
            if(w[x.first] <= m and w[x.second] <= m){
                g[x.first].push_back(x.second);
                g[x.second].push_back(x.first);
            }
        }
        bool flag = false;
        for(int i = 1; i <= n; i++){
            if(!vis[i]){
                node.clear();
                DFS(i, 0);
                int len = -1, nod = 0;
                for(auto x : node){
                    if(lvl[x] > len){
                        len = lvl[x];
                        nod = x;
                    }
                    lvl[x] = 0;
                    vis[x] = false;
                }
                len = -1;
                node.clear();
                DFS(nod, 0);
                for(auto x : node){
                    len = max(len, lvl[x]);
                }
                if(len >= k)flag = true;
            }
        }
        if(flag){
            ans = m;
            r = m - 1;
        }else l = m + 1;
    }
    cout << ans << '\n';
    return 0;
}
