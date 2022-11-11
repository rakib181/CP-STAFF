#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1, M = 20;
vector<int> g[N];
vector<int> lvl(N, 0);
vector<vector<int>> Par(N, vector<int> (M));

void dfs(int cur, int  par){
    Par[cur][0] = par;
    for(int i = 1; i < M; i++){
        Par[cur][i] = Par[Par[cur][i - 1]][i - 1];
    }
    for(auto x : g[cur]){
        if(x != par){
            lvl[x] = lvl[cur] + 1;
            dfs(x, cur);
        }
    }
}

int LCA(int u, int v){
    if(lvl[u] < lvl[v]){
        swap(u, v);
    }
    if(u == v)return u;
    int dist = lvl[u] - lvl[v];
    for(int i = 0; i < M; i++){
        if((dist >> i) & 1){
            u = Par[u][i];
        }
    }
    if(u == v)return u;
    for(int i = M - 1; i >= 0; i--){
        if(Par[u][i] != Par[v][i]){
            u = Par[u][i], v = Par[v][i];
        }
    }
    return Par[u][0];
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    for(int i = 2; i <= n; i++){
        int x;
        cin >> x;
        g[x].push_back(i);
    }
    dfs(1, 0);
    while(q--){
        int x, k;
        cin >> x >> k;
        cout << LCA(x, k) << '\n';
    }
    return 0;
}
