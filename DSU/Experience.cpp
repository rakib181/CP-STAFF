#include <bits/stdc++.h>
using namespace std;

class DSU{
public:
    vector<long long> P, R, ADD;
    void init(long long n){
        P.resize(n);
        R.resize(n, 1);
        ADD.resize(n, 0);
        iota(P.begin(), P.end(), 0);
    }

    long long FIND(long long v){
        if(P[v] == v)return v;
        return FIND(P[v]);
    }

    void UNION(long long u, long long v){
        u = FIND(u), v = FIND(v);
        if(u == v)return;

        if(R[u] > R[v])swap(u, v);
        P[u] = v;
        ADD[u] -= ADD[v];
        R[v]++;
    }

    long long QUERY(long long x){
        if(P[x] == x)return ADD[x];
        return ADD[x] + QUERY(P[x]);
    }
}DS;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n, m;
    cin >> n >> m;
    DS.init(n + 5);
    while(m--) {
        string s;
        cin >> s;
        if (s == "add") {
            long long x, val;
            cin >> x >> val;
            DS.ADD[DS.FIND(x)] += val;
        } else if (s == "join") {
            long long u, v;
            cin >> u >> v;
            DS.UNION(u, v);
        } else {
            long long v;
            cin >> v;
            cout << DS.QUERY(v) << '\n';
        }
    }
    return 0;
}
