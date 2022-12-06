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
    int n;
    cin >> n;
    DS.init(n + 26);
    for(int i = 0; i < n; i++){
       string s;
       cin >> s;
       for(auto x: s){
           DS.UNION(i, x - 'a' + n);
       }
    }
    int cc = 0;
    for(int i = 0; i < n; i++){
        if(DS.FIND(i) == i)cc++;
    }
    cout << cc << '\n';
    return 0;
}
