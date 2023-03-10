#include<bits/stdc++.h>
using namespace std;
#define int long long int

struct BipartiteMatching{
    int n{}, m{};
    vector<int> *g{}, match;
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
            if(g[i].empty())continue;
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
        cout << "Case " << cs++ << ": ";
        int n, m;
        cin >> n >> m;
        G.init(n, m);
        vector<pair<pair<int, int>, int>> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i].first.first >> a[i].first.second >> a[i].second;
        }
        for(int i = 0; i < m; i++){
           int x, y, z;
           cin >> x >> y >> z;
           for(int j = 0; j < n; j++){
               if(abs(a[j].first.first - x) <= 12 and abs(a[j].first.second - y) <= 5 and (a[j].second == z)){
                   G.add_edge(j, i);
               }
           }
        }
        cout << G.maxMatching() << '\n';
    }
    return 0;
}
