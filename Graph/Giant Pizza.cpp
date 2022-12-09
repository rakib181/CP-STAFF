#include<bits/stdc++.h>
using namespace std;
#define int long long int

const int N = 2e5 + 9;
vector<int> g[N], rev_g[N], top;
bool vis[N];

void dfs(int cur){
    vis[cur] = true;
    for(auto x: g[cur]){
        if(!vis[x]){
            dfs(x);
        }
    }
    top.push_back(cur);
}
int comp[N];
void scc(int cur, int cc){
    vis[cur] = true, comp[cur] = cc;
    for(auto x : rev_g[cur]){
        if(!vis[x]){
            scc(x, cc);
        }
    }
}

int32_t main() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
        int m, n;
        cin >> m >> n;
        for(int i = 1; i <= m; i++){
            char ch, chh; int u, v;
            cin >> ch >> u >> chh >> v;

            if(ch == '-') u = 2 * n - u + 1;

            if(chh == '-') v = 2 * n - v + 1;

            g[2 * n - u + 1].push_back(v);
            g[2 * n - v + 1].push_back(u);
            rev_g[u].push_back(2 * n - v + 1);
            rev_g[v].push_back(2 * n - u + 1);
        }
         for(int i = 1; i <= 2 * n; i++){
            if(!vis[i]){
                dfs(i);
            }
        }
        memset(vis, false, sizeof vis);
        int cc = 0;
        reverse(top.begin(), top.end());
        for(auto i : top){
            if(!vis[i]){
                scc(i, cc++);
            }
        }
        vector<bool> ans(n + 1, false);
        for(int i = 1; i <= n; i++){
            if(comp[i] == comp[2 * n - i + 1]){
               cout << "IMPOSSIBLE" << '\n';
                return 0;
            }
            ans[i] = (comp[i] > comp[2 * n - i + 1]);
        }
        for(int i = 1; i <= n; i++){
            ans[i] ? cout << '+'  <<  ' ' : cout << '-' << ' ';
        }
   return 0;
}
