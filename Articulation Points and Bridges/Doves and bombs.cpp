#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 100009;
vector<int> g[N], in(N), low(N);
vector<bool> vis(N); int timer;
vector<pair<int, int>> a(N);

void DFS(int cur, int par){
    vis[cur] = true;
    in[cur] = low[cur] = timer++;
    for(auto x : g[cur]){
        if(!vis[x]){
           DFS(x, cur);
           low[cur] = min(low[cur], low[x]);
           if(low[x] >= in[cur]){
               a[cur].second += 1;
           }
        }else if(x != par){
            low[cur] = min(low[cur], in[x]);
        }
    }
    if(par == -1){
        a[cur].second -= 1;
    }
}

bool cmp(pair<int, int> &aa, pair<int, int> &bb){
    if(aa.second == bb.second){
        return aa.first < bb.first;
    }
    return aa.second > bb.second;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    while (cin >> n >> m, n and m){
        for(int i = 0; i <= n; i++){
            g[i].clear();
            low[i] = in[i] = 0;
            vis[i] = false;
            a[i] = {i, 0};
        }
        while (true){
            int u, v;
            cin >> u >> v;
            if(!~u and !~v)break;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        timer = 1;
        DFS(0, -1);
        sort(a.begin(), a.begin() + n, cmp);
        for(int i = 0; i < m; i++){
            cout << a[i].first << ' ' << a[i].second + 1 << '\n';
        }
        cout << '\n';
    }
    return 0;
}
