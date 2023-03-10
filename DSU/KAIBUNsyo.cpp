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
    int n, mx = 0;
    cin >> n;
    vector<int> a(n);
    set<int> st;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        st.insert(a[i]);
        mx = max(mx, a[i]);
    }
    DS.init(mx + 5);
    int l = 0, r = n - 1;
    while (l <= r){
       DS.UNION(a[l++], a[r--]);
    }
    int tot = (int) st.size();
    for(auto x : st){
        if(DS.FIND(x) == x) tot -= 1;
    }
    cout << tot << '\n';
    return 0;
}
