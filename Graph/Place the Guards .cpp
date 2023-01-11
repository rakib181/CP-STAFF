#include<bits/stdc++.h>
using namespace std;

const int N = 205;
vector<int> g[N], col(N);

int BFS(int src){
    queue<int> q;
    q.push(src);
    col[src] = 1;
    int tot = 0, c = 0;
    while (!q.empty()){
        int node = q.front();
        q.pop();
        tot++;
        if(col[node] == 1)c++;
        for(auto x : g[node]){
            if(col[x] == 2){
                col[x] = 1 - col[node];
                q.push(x);
            }else if(col[x] == col[node]){
                return -1;
            }
        }
    }
    if(tot == 1)return 1;
    else return min(tot - c, c);
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < N; i++){
            g[i].clear();
            col[i] = 2;
        }
        for(int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        bool impossible = false;
        int ans = 0;
        for(int i = 0; i < n and !impossible; i++){
            if(col[i] == 2){
                int guards = BFS(i);
                if(guards == -1){
                    impossible = true;
                }else ans += guards;
            }
        }
        if(!impossible)cout << ans << '\n';
        else cout << "-1" << '\n';
    }
    return 0;
}
