#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
vector<int> g[N];
vector<int> sz(N, 1);

void dfs(int cur, int par){
    for(auto x : g[cur]){
        if(x != par){
            dfs(x, cur);
            sz[cur] += sz[x];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 2; i <= n; i++){
        int x;
        cin >> x;
        g[x].push_back(i);
    }
    dfs(1, -1);
    for(int i = 1; i <= n; i++){
        cout << sz[i] - 1 << ' ';
    }
    return 0;
}
