#include<bits/stdc++.h>
using namespace std;


class DSU{
public:
    vector<long long> P, R;
    void init(int n){
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

        if(R[u] > R[v]){
            swap(u, v);
        }
        P[v] = u;
        R[u]++;
    }
}DS;

long long buildRoads(vector<vector<long long>>Coordinates){
    long long n = (long long) Coordinates.size();
    DS.init(n * 5);
    vector<array<long long, 2>> x, y;
    for(long long i = 0; i < n; i++){
        x.push_back({Coordinates[i][0], i});
        y.push_back({Coordinates[i][1], i});
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    vector<array<long long, 3>> edges;
    for(long long i = 1; i < n; i++){
        edges.push_back({x[i][0] - x[i - 1][0], x[i - 1][1], x[i][1]});
    }
    for(long long i = 1; i < n; i++){
        edges.push_back({y[i][0] - y[i - 1][0], y[i - 1][1], y[i][1]});
    }
    sort(edges.begin(), edges.end());
    long long ans = 0LL;
    for(long long i = 0; i < (int) edges.size(); i++){
        if(DS.FIND(edges[i][1]) != DS.FIND(edges[i][2])){
            DS.UNION(edges[i][1], edges[i][2]);
            ans += edges[i][0];  
        }
    }
    return ans;
}

int main(){
    vector<vector<long long>> Coordinates = {
            {8,3},{4,9},{12,19},{18,1},{13,5},{7,6}
    };
    cout << buildRoads(Coordinates) << '\n';
    return 0;
}
