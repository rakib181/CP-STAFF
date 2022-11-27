#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int N = 1e3 + 9;
vector<int> g[N];
vector<int> a(N);
vector<bool> vis(N);
int sz, amount;

void dfs(int cur){
    vis[cur] = true;
    amount += a[cur];
    sz++;
    for(auto  x : g[cur]){
        if(!vis[x]){
            dfs(x);
        }
    }
}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt, idx = 1;
    cin >> tt;
    while (tt--) {
        cout << "Case " << idx++ << ": ";
        int n, m, sum = 0;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            sum += a[i];
            vis[i] = false;
            g[i].clear();
        }
        int avg = sum / n;
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        bool ok = true;
        if(sum % n != 0) ok = false;
        if(ok) {
            for(int i = 1; i <= n; i++){
                if(!vis[i]){
                    sz = 0, amount = 0;
                    dfs(i);
                    if(amount % sz != 0 or amount / sz != avg){
                        ok = false;
                        break;
                    }
                }
            }
        }
        if (ok)cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
    return 0;
}
