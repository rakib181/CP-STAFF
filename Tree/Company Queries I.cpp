#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1, M = 20;
vector<int> g[N];
vector<vector<int>> Par(N, vector<int> (M));

void dfs(int cur, int  par){
    Par[cur][0] = par;
    for(int i = 1; i < M; i++){
        Par[cur][i] = Par[Par[cur][i - 1]][i - 1];
    }
    for(auto x : g[cur]){
        if(x != par){
            dfs(x, cur);
        }
    }
}

int find_kth_par(int x, int k){
    int cur = x;
    for(int i = 0; i < M; i++){
        if((k >> i) & 1){
           cur = Par[cur][i];
        }
    }
    return cur != 0 ? cur : -1;
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
        g[i].push_back(x);
    }
    dfs(1, 0);
    while(q--){
        int x, k;
        cin >> x >> k;
        cout << find_kth_par(x, k) << '\n';
    }
    return 0;
}
