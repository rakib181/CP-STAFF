#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
vector<pair<int, int>> g[N];
int col[N];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].emplace_back(w, v);
        g[v].emplace_back(w, u);
    }
    int ans = 2e9;
    for(int i = 1; i <= n; i++){
        if((int) g[i].size() >= 2){
            sort(g[i].begin(), g[i].end());
            ans = min(ans, g[i][0].first + g[i][1].first);
        }
    }
    auto f = [&](int x){
        for(int i = 1; i <= n; i++){
            col[i] = -1;
        }
        for(int i = 1; i <= n; i++){
            if(col[i] != -1)continue;
            queue<int> q;
            q.push(i);
            col[i] = 0;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(auto [w, v] : g[node]){
                    if(w < x) {
                        if (col[v] == -1) {
                            col[v] = col[node] ^ 1;
                            q.push(v);
                        }else if(col[v] == col[node]){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    };
    int l = 0, r = ans;
    while(l <= r){
        int mid = l + ((r - l) >> 1);
        if(f(mid)){
            ans = mid;
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    cout << ans << '\n';
    return 0;
}
