#include<bits/stdc++.h>
using namespace std;
using ll = long long;
struct node{
    int u, v, w;
};
const ll inf = 2e18 + 7;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<node> edge(m);
    for(int i = 0; i < m; i++){
        cin >> edge[i].u >> edge[i].v >> edge[i].w;
        edge[i].w *= -1;
    }
    vector<ll> d(n + 1, inf);
    d[1] = 0; int x;
    for(int i = 0; i < n; i++){
        for(auto [u, v, w] : edge){
            if(d[u] == inf)continue;
            d[v] = min(d[v], d[u] + w);
        }
    }
    vector<bool> cycle(n + 1, false);
    for(int i = 0; i < n; i++){
        for(auto [u, v, w] : edge){
            if(d[u] == inf)continue;
            if(d[v] > d[u] + w){
                d[v] = d[u] + w;
                cycle[v] = true;
            }
        }
    }
    if(cycle[n]){
        cout << "inf\n";
        return 0;
    }
    cout << -1LL * d[n] << '\n';
    return 0;
}
