#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
vector<int> g[N]; int mx_d;

class DSU{
public:
    vector<int> P, SZ;
    void init(int n){
        P.resize(n);
        SZ.resize(n, 1);
        iota(P.begin(), P.end(), 0);
    }

    int FIND(int v){
        if(P[v] == v)return v;
        return P[v] = FIND(P[v]);
    }

    void UNION(int u, int v){
        u = FIND(u), v = FIND(v);
        if(u == v)return;

        if(SZ[u] > SZ[v]){
            swap(u, v);
        }
        P[v] = u;
        SZ[u] += SZ[v];
    }
}DS;

void dfs(int cur, int par, int d, int &x){
    if(mx_d <= d){
        x = cur, mx_d = d;
    }
    for(auto xx : g[cur]){
        if(xx != par){
            dfs(xx, cur, d + 1, x);
        }
    }
}

void DFS(int cur, int par, int *dis){
    for(auto x : g[cur]){
        if(x != par){
            dis[x] = dis[cur] + 1;
            DFS(x, cur, dis);
        }
    }
}

signed main(){
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
    mx_d = 0; int x, y;
    dfs(1, -1, 0, x);
    mx_d = 0;
    dfs(x, -1, 0, y);
    int dx[n + 1], dy[n + 1];
    for(int i = 0; i <= n; i++){
        dx[i] = dy[i] = 0;
    }
    DFS(x, -1, dx);
    DFS(y, -1, dy);
    vector<int> forX[n + 1], forY[n + 1];
    for(int i = 1; i <= n; i++){
        forX[dx[i]].push_back(i);
        forY[dy[i]].push_back(i);
    }
    DS.init(n + 5);
    int ans[n + 1], cnt = n;
    for(int i = n; i >= 1; i--){
        for(auto xx : forX[i]){
            if(DS.FIND(x) != DS.FIND(xx)) {
                DS.UNION(x, xx), cnt -= 1;
            }
        }
        for(auto yy : forY[i]){
            if(DS.FIND(y) != DS.FIND(yy)){
                DS.UNION(y, yy), cnt -= 1;
            }
        }
        ans[i] = cnt;
    }
    for(int i = 1; i <= n; i++){
        cout << ans[i] << ' ';
    }
    return 0;
}
