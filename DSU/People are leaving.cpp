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
        P[u] = v;
    }
}DS;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    DS.init(n + 2);
    for(int i = 0; i < m; i++){
        char ch; int x;
        cin >> ch >> x;
        if(ch == '-'){
            DS.UNION(x, x + 1);
        }else{
            int q = DS.FIND(x);
            if(q == n + 1)cout << "-1" << '\n';
            else cout << q << '\n';
        }
    }
    return 0;
}
