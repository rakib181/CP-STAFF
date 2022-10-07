#include <bits/stdc++.h>
using  namespace std;

class DSU{
public:
    vector<int> P, R;
    void init(int n){
       P.resize(n);
       R.resize(n, 1);
       iota(P.begin(), P.end(), 0);
    }

    int FIND(int v){
        if(P[v] == v)return v;

        return P[v] = FIND(P[v]);
    }

    void UNION(int u, int v){
        u = FIND(u), v = FIND(v);
        if(u == v)return;

        if(R[u] > R[v]){
            swap(u, v);
        }
        P[v] = u;
        R[u]++;
    }
}DS;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    DS.init(n + 5);
    for(int i = 0; i < m; i++){
        string s; int u, v;
        cin >> s;
        if(s == "union"){
            cin >> u >> v;
            DS.UNION(u, v);
        }else{
            cin >> u >> v;
            if(DS.FIND(u) == DS.FIND(v)){
                cout << "YES" << '\n';
            }else cout << "NO" << '\n';
        }
    }
    return 0;
}
