#include<bits/stdc++.h>
using namespace std;
#define long long long int

int ask(int a, int b){
    cout << "? " << a << ' ' << b << endl;
    int x;
    cin >> x;
    return x;
}
const int N = 1e3 + 9;
vector<pair<int, int>> ans;
vector<int> vis(N);

void dfs(int u, int v){
    if(vis[v])return;
    int node = ask(u, v);
    if(u == node){
        vis[u] = 1;
        vis[v] = 1;
        ans.emplace_back(u, v);
        return;
    }
    dfs(u, node);
    dfs(node, v);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
       int n;
       cin >> n;
       ans.clear();
       for(int i = 1; i <= n; i++)vis[i] = 0;
       for(int i = 2; i <= n; i++){
           dfs(1, i);
       }
       cout << "! ";
       for(int i = 0; i < n - 1; i++){
           cout << ans[i].first << ' ' << ans[i].second << ' ';
       }
       cout << endl;
    }
    return 0;
}
