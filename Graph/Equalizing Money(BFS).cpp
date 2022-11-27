#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int N = 1e4 + 9;
vector<int> g[N];
vector<int> a(N);
vector<bool> vis(N);
int sz, amount;
set<int> st;

bool bfs(int cur){
    queue<int> q;
    q.push(cur);
    amount += a[cur];
    sz++;
    vis[cur] = true;
    while (!q.empty()){
        int node = q.front();
        q.pop();
        for(auto x : g[node]){
            if(!vis[x]){
                vis[x] = true;
                amount += a[x];
                sz++;
                q.push(x);
            }
        }
    }
    if(amount % sz != 0)return false;
    else{
        st.insert(amount / sz);
        return true;
    }
}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt, idx = 1;
    cin >> tt;
    while (tt--) {
        a.clear();
        cout << "Case " << idx++ << ": ";
        int n, m, sum = 0;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            sum += a[i];
            vis[i] = false;
            g[i].clear();
        }
        st.clear();
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
                     if(!bfs(i)) {
                         ok = false;
                         break;
                     }
                }
            }
        }
         if(ok){
             if((int) st.size() == 1)cout << "Yes" << '\n';
             else cout << "No" << '\n';
         }else cout << "No" << '\n';
    }
    return 0;
}
