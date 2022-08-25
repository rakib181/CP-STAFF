#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9;
vector<int> g[N];
vector<bool> vis(N, false);
vector<int> conn_com(N, 0);
int con_com;

void dfs(int cur){
    vis[cur] = true;
    conn_com[cur] = con_com;
    for(auto x : g[cur]){
        if(!vis[x]){
            dfs(x);
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < N; i++)g[i].clear(), vis[i] = false, conn_com[i] = 0;
    vector<pair<int, int>> query;
    for(int i = 0;i < k; i++){
        int a, b; string s;
        cin >> a >> s >> b;
        if(s == "="){
            g[a].push_back(b);
            g[b].push_back(a);
        }else{
            query.push_back({a, b});
        }
    }
    con_com = 0;
    for(int i = 1; i <= n; i++){
        con_com++;
        if(!vis[i]){
            dfs(i);
        }
    }
    bool ok = false;
    for(auto x : query){
        if(conn_com[x.first] == conn_com[x.second]){
           ok = true;
           break;
        }
    }
    if(ok) cout << "NO" << '\n';
    else cout << "YES" << '\n';
    }
    return 0;
}
