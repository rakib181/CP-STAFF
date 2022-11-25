#include<bits/stdc++.h>
using namespace std;

class DSU{
public:
    int n;
    vector<int> P;
    void INIT(int _n){
        this -> n = _n;
        P.resize(this -> n);
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

int  main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    DS.INIT(n + 5);
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        int temp = DS.FIND(x);
        cout << temp << ' ';
        int vv = temp + 1;
        if ((vv % (n + 1)) == 0)vv = 1;
        DS.UNION(temp, vv);
    }
    return 0;
}
