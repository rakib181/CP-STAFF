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
    DS.init(26);
    string a, b, c;
    cin >> a >> b >> c;
    for(int i = 0; i < (int) a.size(); i++){
        int u = a[i] - 'a';
        int v = b[i] - 'a';
        DS.UNION(u, v);
    }
    string ans;
    for(auto x : c){
        int f = DS.FIND(x - 'a');
        for(int i = 0; i < 26; i++){
            if(DS.FIND(i) == f){
                ans += (i  + 'a');
                break;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
