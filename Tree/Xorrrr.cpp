#include<bits/stdc++.h>
using namespace  std;
#define int long long int
const int N = 1e5 + 9;
vector<int> g[N], sub(N); int n, sum = 0;

void dfs(int cur, int par){
    sub[cur] = 1;
    for(auto x : g[cur]){
        if(x != par){
            dfs(x, cur);
            sub[cur] += sub[x];
        }
    }
    for(auto x : g[cur]){
        if(x != par){
            int c = sub[x] * (n - sub[x]);
            c %= 2;
            if(c){
                sum ^= (x + cur);
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, -1);
    cout << sum << '\n';
    return 0;
}
