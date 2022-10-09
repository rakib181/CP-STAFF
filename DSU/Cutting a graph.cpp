#include <bits/stdc++.h>
using namespace std;

class DSU{
public:
    vector<long long> P, R;
    void init(long long n){
        P.resize(n);
        R.resize(n, 1);
        iota(P.begin(), P.end(), 0);
    }

    long long FIND(long long v){
        if(P[v] == v)return v;
        return P[v] = FIND(P[v]);
    }

    void UNION(long long u, long long v){
        u = FIND(u), v = FIND(v);
        if(u == v)return;
        if(R[u] > R[v])swap(u, v);
        P[u] = v;
        R[v]++;
    }
}DS;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n, m, q;
    cin >> n >> m >> q;
    DS.init(n + 5);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
    }
    vector<pair<string, pair<int, int>>> query;
    for(int i = 0; i < q; i++){
        string s; int u, v;
        cin >> s >> u >> v;
        query.push_back({s, {u, v}});
    }
    vector<string> ans;
    while(!query.empty()){
        auto it = query.back();
        string s = it.first;
        int u = it.second.first;
        int v = it.second.second;
        if(s == "cut"){
            DS.UNION(u, v);
        }else{
            if(DS.FIND(u) == DS.FIND(v)){
                ans.emplace_back("YES");
            }else ans.emplace_back("NO");
        }
        query.pop_back();
    }
    for(int i = (int) ans.size() - 1; i >= 0; i--){
        cout << ans[i] << '\n';
    }
    return 0;
}
