#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 105;
vector<int> g[N];
vector<int> a(N);
int ans, node;

void DFS(int cur){
    int mx = 0, vertex = -1;
    for(auto x : g[cur]){
        if(a[x] > mx)mx = a[x], vertex = x;
    }
    if(vertex != -1)ans += mx, node = vertex, DFS(node);
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt, cs = 1;
    cin >> tt;
    while (tt--){
        for(int i = 0; i < N; i++){
            g[i].clear();
            a[i] = 0;
        }
       int n, m;
       cin >> n >> m;
       for(int i = 0; i < n; i++)cin >> a[i];
       for(int i = 0; i < m; i++){
           int u, v;
           cin >> u >> v;
           g[u].push_back(v);
       }
       ans = 0, node = 0;
       DFS(0);
       cout << "Case " << cs++ << ": " << ans << ' ' << node << '\n';
    }
    return 0;
}
