#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
vector<int> g[N];
int col[N]; bool f = false;
vector<int> order;

void dfs(int u){
    if(f)return;
    col[u] = 1;
    for(auto x : g[u]){
        if(f)return;
        if(!col[x]){
            dfs(x);
        }else if(col[x] == 1){
            f = true;
            return;
        }
    }
    col[u] = 2;
    order.emplace_back(u);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
       int n, m;
       cin >> n >> m;
        for(int i = 1; i <= m; i++){
            int u, v;
            cin >> u >> v;
            g[u].emplace_back(v);
        }
        for(int i = 1; i <= n; i++){
            if(!col[i] and !f){
                dfs(i);
            }
        }
        if(f){
            cout << "IMPOSSIBLE\n";
            return 0;
        }
        reverse(order.begin(), order.end());
        for(auto  x: order){
            cout << x << ' ';
        }
        cout << '\n';
    return 0;
}
