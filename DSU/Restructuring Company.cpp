#include<bits/stdc++.h>
using namespace std;
#define int long long int

class Node{
public:
    int par, next_par;
};

class DSU{
public:
    vector<Node> P; vector<int> SZ;
    void init(int n){
        P.resize(n);
        SZ.resize(n, 1);
        for(int i = 1; i < n; i++){
            P[i].par = i;
            P[i].next_par = i + 1;
        }
    }

    int FIND(int v){
        if(P[v].par == v)return v;
        return P[v].par = FIND(P[v].par);
    }

    void UNION(int u, int v){
        u = FIND(u), v = FIND(v);
        if(u == v)return;

        if(SZ[u] > SZ[v]){
            swap(u, v);
        }
        P[v].par = u;
        SZ[u] += SZ[v];
    }
}DS;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    DS.init(n + 5);
    for(int i = 0; i < m; i++){
        int x, u, v;
        cin >> x >> u >> v;
        if(x == 1){
            DS.UNION(u, v);
        }else if(x == 2){
           for(int ii = u + 1, next ; ii <= v; ii = next) {
               DS.UNION(ii - 1, ii);
               next = DS.P[ii].next_par;
               DS.P[ii].next_par = DS.P[v].next_par;
           }
        }else {
            if(DS.FIND(u) == DS.FIND(v)){
                cout << "YES" << '\n';
            }else cout << "NO" << '\n';
        }
    }
    return 0;
}
