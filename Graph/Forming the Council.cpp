#include<bits/stdc++.h>
using namespace std;
#define int long long int

const int N = 16009;
vector<int> g[N], rev_g[N], top, comp(N);
vector<bool> vis(N);

int cal(int x){
    if(x < 0){
        x *= -1;
        x--;
        return (x << 1) + 1;
    }
    x--;
    return (x << 1);
}

void dfs(int cur){
    vis[cur] = true;
    for(auto x: g[cur]){
        if(!vis[x]){
            dfs(x);
        }
    }
    top.push_back(cur);
}

void scc(int cur, int cc){
    comp[cur] = cc;
    for(auto x : rev_g[cur]){
        if(comp[x] == -1){
            scc(x, cc);
        }
    }
}

int32_t main() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   int tt, cs = 1;
   cin >> tt;
    while (tt--){
        cout << "Case " << cs++ << ": ";
        int m, n;
        cin >> m >> n;
        top.clear();
        for(int i = 0; i < (n << 1); i++){
           g[i].clear();
           rev_g[i].clear();
           comp[i] = -1;
           vis[i] = false;
        }
        for(int i = 1; i <= m; i++){
            int u, v;
            cin >> u >> v;
            u = cal(u);
            v = cal(v);
            g[u ^ 1].push_back(v);
            g[v ^ 1].push_back(u);
            rev_g[u].push_back(v ^ 1);
            rev_g[v].push_back(u ^ 1);
        }
        for(int i = 0; i < (n << 1); i++){
            if(!vis[i]){
                dfs(i);
            }
        }
        int cc = 0;
        reverse(top.begin(), top.end());
        for(int i = 0; i < (int) top.size(); i++){
            if(comp[top[i]] == -1){
                scc(top[i], cc++);
            }
        }
        bool ok = true;
        for(int i = 0; i < (n << 1); i += 2){
            if(comp[i] == comp[i + 1]){
                ok = false;
                break;
            }
        }
        if(ok){
            cout << "Yes" << '\n';
            vector<int> ans;
            for(int i = 0; i < (n << 1); i += 2){
                if(comp[i] > comp[i + 1])ans.push_back((i >> 1));
            }
            cout << (int) ans.size() << ' ';
            for(auto x : ans){
                cout << x + 1 << ' ';
            }
            cout << '\n';
        }else cout << "No" << '\n';
    }
   return 0;
}
