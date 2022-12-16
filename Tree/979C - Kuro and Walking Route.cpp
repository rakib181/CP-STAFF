#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 3e5 + 9;
vector<int> g[N], subtree_sz(N, 1);
vector<bool> s_d(N);
int n, x, y;

void DFS(int cur, int par){
    if(cur == x){
        s_d[cur] = true;
    }else s_d[cur] = false;
    for(auto xx : g[cur]){
        if(xx != par){
          DFS(xx, cur);
          subtree_sz[cur] += subtree_sz[xx];
          s_d[cur] = s_d[cur] | s_d[xx];
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> x >> y;
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    DFS(y, -1); int ex;
    for(auto xx : g[y]){
        if(s_d[xx]){
            ex = subtree_sz[y] - subtree_sz[xx];
            break;
        }
    }
    cout << n * (n - 1) - ex * subtree_sz[x] << '\n';
    return 0;
}
