#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 9;
int n, h[N], in[N], ou[N], col[N], t[4 * N];
vector<int> g[N];

void build(int node, int b, int e){
    if(b == e){
        t[node] = h[b];
        return;
    }
    int mid = (b + e) >> 1;
    build(2 * node, b, mid);
    build(2 * node + 1, mid + 1, e);
    t[node] = max(t[2 * node], t[2 * node + 1]);
}

void upd(int node, int b, int e, int i, int v){
    if(b > i or e < i)return;
    if(b == e){
        t[node] = v;
        return;
    }
    int mid = (b + e) >> 1;
    upd(2 * node, b, mid, i, v);
    upd(2 * node + 1, mid + 1, e, i, v);
    t[node] = max(t[2 * node], t[2 * node + 1]);
}

int query(int node, int b, int e, int l, int r){
    if(b > r or e < l)return -1;
    if(b >= l and e <= r)return t[node];
    int mid = (b + e) >> 1;
    return max(query(2 * node, b, mid, l, r), query(2 * node + 1, mid + 1, e, l, r));
}
int tme;
void dfs(int u, int p, int height){
    in[u] = ++tme;
    h[u] = height;
    for(auto v : g[u]){
        if(v == p)continue;
        dfs(v, u, height + 1);
    }
    ou[u] = tme;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
         tme = 0;
         cin >> n;
         for(int i = 1; i <= n; i++){
             in[i] = ou[i] = col[i] = 0;
             h[i] = -1;
             g[i].clear();
         }
         for(int i = 1; i <= 4 * n; i++){
             t[i] = -1;
         }
         build(1, 1, n);
         for(int i = 1; i <= n - 1; i++){
             int u, v;
             cin >> u >> v;
             g[u].emplace_back(v);
             g[v].emplace_back(u);
         }
         dfs(1, 0, 0);
         int m;
         cin >> m;
         while(m--){
             int type;
             cin >> type;
             if(type == 1){
                 int node;
                 cin >> node;
                 if(col[node] == 0){
                     upd(1, 1,  n, in[node], h[node]);
                 }else{
                     upd(1, 1, n, in[node], -1);
                 }
                 col[node] ^= 1;
             }else{
                 int node;
                 cin >> node;
                 int ans = query(1, 1,  n, in[node], ou[node]);
                 if(ans != -1)ans -= h[node];
                 cout << ans << '\n';
             }
         }
    }
    return 0;
}
