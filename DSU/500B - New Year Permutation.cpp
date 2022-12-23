#include<bits/stdc++.h>
using namespace std;
#define int long long int

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


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    DS.init(n + 2);
    vector<int> p(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> p[i];
    }
    vector<vector<char>> a(n + 1, vector<char> (n + 1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            if(a[i][j] == '1')DS.UNION(i, j);
        }
    }
    vector<vector<int>> ans(n + 1);
    for(int i = 1; i <= n; i++){
        int par = DS.FIND(i);
        ans[par].push_back(p[i]);
    }
    for(int i = 1; i <= n; i++){
        sort(ans[i].begin(), ans[i].end());
    }
    vector<int> idx(n + 1, 0);
    for(int i = 1; i <= n; i++){
        int par = DS.FIND(i);
        cout << ans[par][idx[par]++] << ' ';
    }
    return 0;
}
