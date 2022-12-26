#include<bits/stdc++.h>
using namespace std;
#define int long long int
int n, m, r;
const int N = 1e6 + 9;
vector<int> g[N];
vector<int> protectedBy(N);

bool BFS(int cur, int strength, int par){
    if(protectedBy[cur])return false;
    queue<pair<int, int>> q;
    q.push({cur, 0});
    protectedBy[cur] = par;
    while (!q.empty()){
        auto it = q.front();
        q.pop();
        int node = it.first;
        int st = it.second;
        if(st >= strength)break;
        for(auto x : g[node]){
            if(!protectedBy[x]){
                protectedBy[x] = par;
                q.push({x, st + 1});
            }else{
                if(protectedBy[x] != par)return false;
            }
        }
    }
    return true;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        cin >> n >> m >> r;
        for(int i = 1; i <= n; i++){
            g[i].clear();
            protectedBy[i] = 0;
        }
        for(int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int ok = true;
        for(int i = 0; i < r; i++){
            int k, s;
            cin >> k >> s;
            if(!BFS(k, s, k)){
                ok = false;
                break;
            }
        }
        for(int i = 1; i <= n; i++){
            if(!protectedBy[i]){
                ok = false;
                break;
            }
        }
        if(ok) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
    return 0;
}
