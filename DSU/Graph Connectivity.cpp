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
        char x;
        cin >> x;
        int n = x - 'A' + 1;
        DS.init(n + 2);
        cin.ignore();

        string s;
        while (getline(cin, s) and !s.empty()){
            int u = s[0] - 'A' + 1, v = s[1] - 'A' + 1;
            if(DS.FIND(u) != DS.FIND(v)){
                DS.UNION(u, v);
            }
        }
        int cc = 0;
        for(int i = 1; i <= n; i++){
            if(DS.FIND(i) == i)cc++;
        }
        cout << cc << '\n';
        if(tt)cout << '\n';
        DS.P.clear(), DS.SZ.clear();
    }
    return 0;
}
