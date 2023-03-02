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


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--){
        int n, k;
        cin >> n >> k;
        string s, t;
        cin >> s >> t;
        DS.init(n + 5);
        for(int i = 0; i < n; i++){
            if(i + k < n){
                DS.UNION(i, i + k);
            }
            if(i + k + 1 < n){
                DS.UNION(i, i + k + 1);
            }
        }
        map<int, string> root[2];
        for(int i = 0; i < n; i++){
            int boss = DS.FIND(i);
            root[0][boss].push_back(s[i]);
            root[1][boss].push_back(t[i]);
        }
        set<int> st;
        for(int i = 0; i < n; i++){
            st.insert(DS.FIND(i));
        }
        bool ok = true;
        for(auto x : st){
            sort(root[0][x].begin(), root[0][x].end());
            sort(root[1][x].begin(), root[1][x].end());
            if(root[0][x] != root[1][x])ok = false;
        }
        if(ok)cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}
