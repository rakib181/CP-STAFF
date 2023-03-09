#include<bits/stdc++.h>
using namespace std;
#define int long long int

struct BipartiteMatching{
    int n, m;
    vector<int> *g, match;
    vector<bool> vis;
    void init(int _n, int _m){
        this -> n = _n;
        this -> m = _m;
        match.assign(n + m + 1, -1);
        vis.assign(n + m + 1, false);
        g = new vector<int> [n + m + 1];
    }

    void add_edge(int u, int v) const{
        g[u].push_back(v + n);
        g[v + n].push_back(u);
    }
    int maxMatching(){
        int ans = 0;
        for(int i = 0; i < n; i++){
            vis.assign(n + m + 1, false);
            if(kuhn(i)) ans += 1;
        }
        return ans;
    }
    bool kuhn(int v){
        if(vis[v])return false;
        vis[v] = true;
        for(auto x : g[v]){
            if(match[x] < 0 or kuhn(match[x])){
                match[x] = v;
                match[v] = x;
                return true;
            }
        }
        return false;
    }
}G;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt, cs = 1;
    cin >> tt;
    while(tt--) {
        int n, m;
        cin >> n >> m;
        G.init(n, m);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int x;
                cin >> x;
                if(x){
                    G.add_edge(i, j);
                }
            }
        }
        cout << "Case " << cs++ << ": a maximum of " << G.maxMatching() << " nuts and bolts can be fitted together" << '\n';
    }
    return 0;
}
