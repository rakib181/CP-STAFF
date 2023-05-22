#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
vector<int> g[N];
int vis[N];

bool dfs(int u, int par = -1){
    vis[u] = 1;
    for(auto x : g[u]){
        if(!vis[x]){
            if(dfs(x, u))return true;
        }else if(x != par and vis[x] == 1)return true;
    }
    vis[u] = 2;
    return false;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++){
            g[i].clear();
            vis[i] = false;
        }
        for(int i = 1; i <= n; i++){
            int x;
            cin >> x;
            g[i].emplace_back(x);
            g[x].emplace_back(i);
        }
        int cycle = 0, cc = 0;
        for(int i = 1; i <= n; i++){
            if(!vis[i]){
                if(dfs(i))cycle += 1;
                cc += 1;
            }
        }
        if(cycle == cc)cout << cc << ' ' << cc << '\n';
        else cout << cycle + 1 << ' ' << cc << '\n';
    }
    return 0;
}
