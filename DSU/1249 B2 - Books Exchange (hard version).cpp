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
    int tt;
    cin >> tt;
    while (tt--){
        int n;
        cin >> n;
        DS.init(n + 2);
        for(int i = 1; i <= n; i++){
            int x;
            cin >> x;
            DS.UNION(i, x);
        }
        for(int i = 1; i <= n; i++){
            cout << DS.SZ[DS.FIND(i)] << ' ';
        }
        DS.P.clear(), DS.SZ.clear();
        cout << '\n';
    }
    return 0;
}
