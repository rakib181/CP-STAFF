#include <bits/stdc++.h>
using namespace std;
const int N = 105;
vector<int> g[N], in(N), low(N);
vector<bool> vis(N), is_cut(N); int timer;

void is_art_point(int node){
    is_cut[node] = true;
}

void dfs(int cur, int par){
    vis[cur] = true;
    in[cur] = low[cur] = timer++;
    int child = 0;
    for(auto x : g[cur]){
        if(x == par)continue;
        if(!vis[x]){
            dfs(x, cur);
            child++;
            low[cur] = min(low[cur], low[x]);
            if(low[x] >= in[cur] and par != -1){
                is_art_point(cur);
            }
        }else{
            low[cur] = min(low[cur], in[x]);
        }
    }
    if(par == -1 and child > 1)is_art_point(cur);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while (cin >> n){
        if(!n)break;
        for(int i = 0; i < N; i++){
            g[i].clear();
            in[i] = low[i] = 0;
            vis[i] = is_cut[i] = false;
        }
        string s;
        while (getline(cin, s), s != "0"){
            stringstream ss(s);
            int u, v;
            ss >> u;
            while (ss >> v){
                g[u].push_back(v);
                g[v].push_back(u);
            }
        }
        for(int i = 1; i <= n; i++){
            if(!vis[i]){
                dfs(i, -1);
            }
        }
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            if(is_cut[i])cnt++;
        }
        cout << cnt << '\n';
    }
    return 0;
}
