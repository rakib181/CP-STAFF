#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct MST{
    vector<vector<int>> t;
    vector<int> a;
    MST(vector<int> &a, int n){
        this -> a.resize(n + 1);
        t.assign(4 * n, vector<int> ());
        for(int i = 1; i <= n; i++){
            this -> a[i] = a[i];
        }
    }
    void build(int node, int b, int e){
        if(b == e){
            t[node].emplace_back(a[b]);
            return;
        }
        int m = (b + e) >> 1;
        build(2 * node, b, m);
        build(2 * node + 1, m + 1, e);
        int i = 0, j = 0, sz_l = (int) t[2 * node].size() - 1, sz_r = (int) t[2 * node + 1].size() - 1;
        while(i <= sz_l and j <= sz_r){
            if(t[2 * node][i] > t[2 * node + 1][j]) {
                t[node].emplace_back(t[2 * node + 1][j++]);
            }else t[node].emplace_back(t[2 * node][i++]);
        }
        while(i <= sz_l)t[node].emplace_back(t[2 * node][i++]);
        while(j <= sz_r)t[node].emplace_back(t[2 * node + 1][j++]);
    }

    bool query(int node, int b, int e, int l, int r, int x, int y){
        if(b > r or e < l)return false;
        if(b >= l and e <= r){
            int L = 0, R = (int) t[node].size() - 1;
            while(L <= R){
                int M = (L + R) >> 1;
                if(t[node][M] >= x and t[node][M] <= y)return true;
                if(t[node][M] < x)L = M + 1;
                else R = M - 1;
            }
            return false;
        }
        int m = (b + e) >> 1;
        return query(2 * node, b, m, l, r, x, y) | query(2 * node + 1, m + 1, e, l, r, x, y);
    }
};
const int N = 1e5 + 9;
vector<int> g[N];
int in[N], ou[N], tme, a[N];

void dfs(int u, int p){
    in[u] = ++tme;
    for(auto v : g[u]){
        if(v != p){
            dfs(v, u);
        }
    }
    ou[u] = tme;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        for(int i = 0; i <= n; i++){
            in[i] = ou[i] = 0;
            g[i].clear();
        }
        tme = 0;
        for(int i = 1; i <= n - 1; i++){
            int u, v;
            cin >> u >> v;
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
        dfs(1, 0);
        for(int i = 1; i <= n; i++)cin >> a[i];
        vector<int> p(n + 1);
        for(int i = 1; i <= n; i++){
            p[i] = in[a[i]];
        }
        MST ms(p, n);
        ms.build(1, 1, n);
        while(q--){
            int l, r, x;
            cin >> l >> r >> x;
            ms.query(1, 1, n, l, r, in[x], ou[x]) ? cout << "YES\n" : cout << "NO\n";
        }
        cout << '\n';
    }
    return 0;
}
