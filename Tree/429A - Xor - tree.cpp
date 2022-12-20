#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 1e5 + 9;
vector<int> g[N], a(N), b(N), ans;

void DFS(int cur, int par, int c, int xx){
    a[cur] ^= c;
    if(a[cur] != b[cur]){
        ans.push_back(cur);
        c ^= 1;
    }
    for(auto x : g[cur]){
        if(x != par){
            DFS(x, cur, xx, c);
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> b[i];
    }
    DFS(1, -1, 0, 0);
    cout << (int) ans.size() << '\n';
    for(auto x : ans)cout << x << '\n';
    return 0;
}
