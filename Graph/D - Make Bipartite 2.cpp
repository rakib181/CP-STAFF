#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 2e5 + 9;
vector<int> g[N], col(N, -1);

pair<int, int> DFS(int cur, int par, int c){
    pair<int, int> p = {0, 0};
    col[cur] = c;
    if(c == 0)p.first++;
    else p.second++;
    for(auto x : g[cur]){
        if(x != par){
            if(col[x] == -1) {
                pair<int, int> xx = DFS(x, cur, c ^ 1);
                if (xx.first == -1)return {-1., -1};
                p.first += xx.first, p.second += xx.second;
            }else{
                if(col[x] == col[cur]){
                    return {-1, -1};
                }
            }
        }
    }
    return p;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans = n * (n - 1) / 2 - m; bool ok = true;
    for(int i = 1; i <= n; i++){
        if(col[i] == -1){
           pair<int, int> p = DFS(i, -1, 0);
           if(p.first == -1){
               ok = false;
               break;
           }
           ans -= p.first * (p.first - 1) / 2;
           ans -= p.second * (p.second - 1) / 2;
        }
    }
    if(ok)cout << ans << '\n';
    else cout << "0" << '\n';
    return 0;
}
