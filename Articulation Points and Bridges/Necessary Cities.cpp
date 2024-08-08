#include<bits/stdc++.h>
using namespace std;
#define long long long

const int N = 1e5 + 9;
vector<int> g[N], d(N), en(N);
vector<pair<int, int>> bridge;
vector<int> points;
int n, m, tme;

void dfs(int u, int p){
    d[u] = en[u] = ++tme;
    int child = 0;
    for(auto v : g[u]){
        if(!d[v]){
            dfs(v, u);
            child++;
            en[u] = min(en[u], en[v]);
            if(d[u] < en[v]){
                bridge.emplace_back(u, v);
            }
            if(en[v] >= d[u] and p != 0){
                points.emplace_back(u);
            }
        }else if(v != p){
            en[u] = min(en[u], d[v]);
        }
    }
    if(u == 1 and child > 1){
        points.emplace_back(u);
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    tme = 0;
    dfs(1, 0);
    sort(points.begin(), points.end());
    points.resize(unique(points.begin(), points.end()) - points.begin());
    cout << (int) points.size() << '\n';
    for(auto x : points){
        cout << x << ' ';
    }
    return 0;
}
