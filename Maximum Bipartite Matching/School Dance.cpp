#include<bits/stdc++.h>
using namespace std;
#define int long long int

struct BipartiteMatching{
    int n{}, m{}, MX = 505;
    vector<int> *g{}, match;
    vector<bool> vis;
    void init(int _n, int _m){
        this -> n = _n;
        this -> m = _m;
        match.assign(MX, -1);
        vis.assign(MX, false);
        g = new vector<int> [MX];
    }

    void add_edge(int u, int v) const{
        g[v].push_back(u);
    }
    int maxMatching(){
        int tot = 0;
        for(int i = 1; i <= m; i++){
            vis.assign(MX, false);
            if(kuhn(i)) tot += 1;
        }
        return tot;
    }
    bool kuhn(int v){
        if(vis[v])return false;
        vis[v] = true;
        for(auto x : g[v]){
            if(match[x] == -1 or kuhn(match[x])){
                match[x] = v;
                return true;
            }
        }
        return false;
    }
}G;


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, e;
    cin >> n >> m >> e;
    G.init(n , m);
    for(int i = 0; i < e; i++){
        int u, v;
        cin >> u >> v;
        G.add_edge(u, v);
    }
    cout << G.maxMatching() << '\n';
    for(int i = 1; i <= n; i++){
        if(G.match[i] != -1){
            cout << i << ' ' << G.match[i] << '\n';
        }
    }
    return 0;
}
