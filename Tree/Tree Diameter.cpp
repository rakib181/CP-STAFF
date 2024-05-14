#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5 + 9;
vector<int> g[N];
vector<int> depth(N, 0);
 
void dfs(int cur, int par = 0){
    for(auto x : g[cur]){
        if(x != par){
            depth[x] = depth[cur] + 1;
            dfs(x, cur);
        }
    }
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    int node = 0, mx = INT_MIN;
    for(int i = 1; i <= n; i++){
        if(depth[i] > mx)mx = depth[i], node = i;
        depth[i] = 0;
    }
    dfs(node); mx = INT_MIN;
    for(int i = 1; i <= n; i++)if(depth[i] > mx)mx = depth[i];
    cout << mx << '\n';
    return 0;
}

// Tree Diameter 
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
vector<int> g[N];
int toLeaf[N], maxLength[N];

void dfs(int u, int p){
    for(auto v : g[u]){
        if(v != p){
            dfs(v, u);
        }
    }
    for(auto v : g[u]){
        if(v != p){
            toLeaf[u] = max(toLeaf[u], toLeaf[v] + 1);
        }
    }
}

void cal(int u, int p){
    vector<int> d;
    for(auto v : g[u]){
        if(v != p){
            cal(v, u);
            d.emplace_back(toLeaf[v]);
        }
    }
    sort(d.rbegin(), d.rend());
    if((int) d.size() == 1){
        maxLength[u] = max(maxLength[u], 1 + d[0]);
    }else if((int) d.size() >= 2){
        maxLength[u] = max(maxLength[u], 2 + d[0] + d[1]);
    }

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs(1, 0);
    cal(1, 0);
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans = max(ans, maxLength[i]);
    }
    cout << ans << '\n';
    return 0;
}
