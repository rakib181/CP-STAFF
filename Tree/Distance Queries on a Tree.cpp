#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 2e5 + 9;
int n, q;
struct fenwick{
    int fn[N];
    void upd(int x, int k){
        for(;x <= n; x += x & (-x)) fn[x] += k;
    }
    int sum(int x){
        int res = 0;
        for(; x > 0; x -= x & (-x)){
            res += fn[x];
        }
        return res;
    }
}mt;

vector<pair<int, pair<int, int>>> g[N]; vector<int> st(N), en(N), a(N), son(N), depth(N);
vector<vector<int>> fa(N, vector<int> (21));
int timer;
void dfs(int cur, int par){
    st[cur] = ++timer; fa[cur][0] = par; depth[cur] = depth[par] + 1;
    for(int i = 1; i < 21; i++){
        fa[cur][i] = fa[fa[cur][i - 1]][i - 1];
    }
    for(auto x : g[cur]){
        if(x.first != par){
            a[x.first] = x.second.first;
            son[x.second.second] = x.first;
            dfs(x.first, cur);
        }
    }
    en[cur] = timer;
    mt.upd(st[cur], a[cur]);
    mt.upd(en[cur] + 1, -a[cur]);
}

int lca(int x, int y){
    if(depth[x] > depth[y])swap(x, y);
    for(int i = 20; i >= 0 and depth[y] > depth[x]; i--){
        if(depth[fa[y][i]] >= depth[x]) y = fa[y][i];
    }
    if(x == y)return x;
    for(int i = 20; i >= 0 and fa[x][0] != fa[y][0]; i--){
        if(fa[y][i] != fa[x][i]){
            x = fa[x][i];
            y = fa[y][i];
        }
    }
    return fa[x][0];
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i = 1; i <= n - 1; i++){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, {w, i}});
        g[v].push_back({u, {w, i}});
    }
    dfs(1, 0);
    cin >> q;
    while (q--){
        int type;
        cin >> type;
        if(type == 1){
            int i, w;
            cin >> i >> w;
            int x = son[i];
            mt.upd(st[x], -a[x]);
            mt.upd(en[x] + 1, a[x]);
            a[x] = w;
            mt.upd(st[x], a[x]);
            mt.upd(en[x] + 1, -a[x]);
        }else{
            int u, v;
            cin >> u >> v;
            int LCA = lca(u, v);
            cout << mt.sum(st[u]) + mt.sum(st[v]) - mt.sum(st[LCA]) * 2 << '\n';
        }
    }
    return 0;
}
