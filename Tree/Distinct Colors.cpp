#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 2e5 + 10;
vector<int> g[N], col(N);
set<int> st[N];


void dfs(int cur, int par){
    for(auto x : g[cur]){
        if(x != par){
            dfs(x, cur);
            if((int)st[cur].size() < (int) st[x].size()){
                swap(st[cur], st[x]);
            }
            for(auto xx : st[x]){
                st[cur].insert(xx);
            }
        }
    }
    col[cur] = (int) st[cur].size();
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        st[i].insert(x);
    }

    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs(1, 0);
    for(int i = 1; i <= n; i++){
        cout << col[i] << ' ';
    }
    return 0;
}
