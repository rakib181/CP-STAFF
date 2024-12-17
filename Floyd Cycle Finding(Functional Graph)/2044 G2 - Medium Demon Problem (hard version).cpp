#include<bits/stdc++.h>
using namespace std;
#define long long long

const int N = 2e5 + 9;
vector<int> g[N], vis(N);

int dfs(int u){
    vis[u] = 1;
    int ans = 1;
    for(auto v : g[u]){
        if(vis[v])continue;
        ans += dfs(v);
    }
    return ans;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> p(n + 1);
        for(int i = 1; i <= n; i++){
            cin >> p[i];
            g[p[i]].emplace_back(i);
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(vis[i])continue;
            int tortoise = i;
            int hare = i;
            do{
                tortoise = p[tortoise];
                hare = p[p[hare]];
            } while (tortoise != hare);
            do{
                vis[hare] = 1;
                hare = p[hare];
            } while (tortoise != hare);

            do{
                for(auto node : g[tortoise]){
                    if(vis[node])continue;
                    ans = max(ans, dfs(node));
                }
                tortoise = p[tortoise];
            } while (tortoise != hare);
        }
        cout << ans + 2 << '\n';
        for(int i = 0; i <= n; i++){
            g[i].clear();
            vis[i] = 0;
        }
    }
    return 0;
}
