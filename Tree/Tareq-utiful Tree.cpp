#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
vector<int> g[N];
int n, c[N], sz[N], u, p;
bool vis[N];

void dfs(int cur, int par){
    sz[cur] = 1;
    for(auto v : g[cur]){
        if(v != par){
            dfs(v, cur);
            sz[cur] += sz[v];
        }
    }
    if(sz[cur] == n / 2){
        u = cur, p = par;
    }
}

void f(int cur, int par){
    vis[cur] = true;
    for(auto v : g[cur]){
        if(v != par){
            f(v, cur);
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; i++){
            g[i].clear();
            sz[i] = 0;
            vis[i] = false;
            c[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            cin >> c[i];
        }
        for (int i = 1; i < n; i++) {
            int a, b;
            cin >> a >> b;
            g[a].emplace_back(b);
            g[b].emplace_back(a);
        }
        if (n & 1) {
            cout << "-1\n";
            continue;
        }
        u = -1, p = -1;
        dfs(1, -1);
        if (u == -1) {
            cout << "-1\n";
            continue;
        }
        f(u, p);
        int cnt1[n + 1], cnt2[n + 1];
        memset(cnt1, 0, sizeof cnt1);
        memset(cnt2, 0, sizeof cnt2);
        for(int i = 1; i <= n; i++){
            if(vis[i])cnt1[c[i]] += 1;
            else cnt2[c[i]] += 1;
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
            int need = (cnt1[i] + cnt2[i]);
            if(need & 1){
                ans = -1;
                break;
            }
            ans += abs(cnt1[i] - need / 2);
        }
        ans == -1 ? cout << ans << '\n' : cout << ans / 2 << '\n';
    }
    return 0;
}
