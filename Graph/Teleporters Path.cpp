#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 1e5 + 9;
set<int> g[N];
vector<int> in(N), out(N);
vector<int> path;

void DFS(int cur){
    while ((int) g[cur].size()){
        auto node = g[cur].begin();
        g[cur].erase(node);
        DFS(*node);
    }
    path.push_back(cur);
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].insert(v);
        in[v]++, out[u]++;
    }
    int cnt = 0, src = 0, des = 0, src_cnt = 0, des_cnt = 0;
    for(int i = 1; i <= n; i++){
        if(in[i] == out[i])cnt++;
        else if(in[i] - out[i] == 1)src_cnt++, des = i;
        else if(in[i] - out[i] == -1)des_cnt++, src = i;
    }
    if(cnt == n - 2 and src_cnt == 1 and des_cnt == 1 and src == 1 and des == n){
        DFS(1);
        if((int) path.size() == m + 1){
            reverse(path.begin(), path.end());
            for(auto x : path){
                cout << x << ' ';
            }
        }else{
            cout << "IMPOSSIBLE" << '\n';
        }
    }else cout << "IMPOSSIBLE" << '\n';

    return 0;
}
