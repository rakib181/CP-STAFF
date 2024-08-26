#include<bits/stdc++.h>
using namespace std;

#define long long long

struct node{
    int u, v, w;
};

const int inf = 1e9 + 7;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, cs = 1;
    cin >> t;
    while(t--){
        cout << "Case " << cs++ << ": ";
        int n, m, p;
        cin >> n >> m >> p;
        vector<node> g(m);
        for(int i = 0; i < m; i++){
            cin >> g[i].u >> g[i].v;
            int in, ex;
            cin >> in >> ex;
            g[i].w = p * ex - in;
        }
        vector<int> d(n, inf);
        bool found = false;
        for(int i = 0; i < n; i++){
            if(d[i] != inf)continue;
            d[i] = 0;
            for(int j = 0; j < n; j++){
                for(auto [u, v, w] : g){
                    if(d[u] == inf)continue;
                    if(d[v] > d[u] + w){
                        d[v] = d[u] + w;
                    }
                }
            }
            bool cycle = false;
            for(int j = 0; j < n; j++){
                for(auto [u, v, w] : g){
                    if(d[u] == inf)continue;
                    if(d[v] > d[u] + w){
                        d[v] = d[u] + w;
                        cycle = true;
                    }
                }
            }
            found |= cycle;
        }
        cout << (found ? "YES\n" : "NO\n");
    }
    return 0;
}
