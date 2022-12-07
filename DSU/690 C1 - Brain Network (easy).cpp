#include<bits/stdc++.h>
using namespace std;

class DSU{
public:
    vector<int> P;
    void init(int n){
        P.resize(n);
        iota(P.begin(), P.end(), 0);
    }

    int FIND(int v){
        if(P[v] == v)return v;
        return P[v] = FIND(P[v]);
    }

    void UNION(int u, int v){
        u = FIND(u), v = FIND(v);
        if(u == v)return;
        P[v] = u;
    }
}DS;


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    DS.init(n + 2);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        DS.UNION(u, v);
    }
    int cc = 0;
    for(int i = 1; i <= n; i++){
        if(DS.FIND(i) == i)cc++;
    }
    (cc == 1 and m == n - 1) ? cout << "yes" << '\n' : cout << "no" << '\n';
    return 0;
}
