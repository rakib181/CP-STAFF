#include<bits/stdc++.h>
using namespace std;
using ll = long long;

class DSU{
public:
    vector<int> P, SZ;
    void INIT(int n){
        P.assign(n, 0);
        SZ.assign(n, 1);
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

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int sz = 5 * n * m;
        DS.INIT(sz);
        vector<vector<char>> g(n + 1, vector<char> (m + 1));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cin >> g[i][j];
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(i + 1 <= n and g[i + 1][j] == '#' and g[i][j] == '#'){
                    int u = i * m + j, v = (i + 1) * m + j;
                    DS.UNION(u, v);
                }
                if(j + 1 <= m and g[i][j + 1] == '#' and g[i][j] == '#'){
                    int u = i * m + j, v = i * m + j + 1;
                    DS.UNION(u, v);
                }
            }
        }
        int ans = 0;
        vector<int> vis(sz, -1);
        for(int r = 1; r <= n; r++){
            int sum = 0;
            for(int i = 1; i <= m; i++){
                if(g[r][i] == '.')sum += 1;
                for(int x = max(1, r - 1); x <= min(n, r + 1); x++){
                    if(g[x][i] == '#'){
                        int p = x * m + i;
                        int lead = DS.FIND(p);
                        if(vis[lead] != r){
                            vis[lead] = r;
                            sum += DS.SZ[lead];
                        }
                    }
                }
            }
            ans = max(ans, sum);
        }
        vis.assign(sz, -1);
        for(int c = 1; c <= m; c++){
            int sum = 0;
            for(int i = 1; i <= n; i++){
                if(g[i][c] == '.')sum += 1;
                for(int x = max(1, c - 1); x <= min(m, c + 1); x++){
                    if(g[i][x] == '#'){
                        int p = i * m + x;
                        int lead = DS.FIND(p);
                        if(vis[lead] != c){
                            vis[lead] = c;
                            sum += DS.SZ[lead];
                        }
                    }
                }
            }
            ans = max(ans, sum);
        }
        cout << ans << '\n';
    }
    return 0;
}
