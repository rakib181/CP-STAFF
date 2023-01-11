#include<bits/stdc++.h>
using namespace std;

const int N = 305;
vector<int> g[N], col(N);

bool BFS(int src){
    queue<int> q;
    q.push(src);
    col[src] = 1;
    while (!q.empty()){
        int node = q.front();
        q.pop();
        for(auto x : g[node]){
            if(col[x] == 2){
                col[x] = 1 - col[node];
                q.push(x);
            }else if(col[x] == col[node]){
                return true;
            }
        }
    }
    return false;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while (cin >> n) {
        if(!n)break;
        for(int i = 0; i < N; i++){
            g[i].clear();
            col[i] = 2;
        }
        while (true){
            int u, v;
            cin >> u >> v;
            if(!u and !v)break;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        bool impossible = false;
        for(int i = 0; i < n and !impossible; i++){
            if(col[i] == 2){
                bool guards = BFS(i);
                if(guards){
                    impossible = true;
                }
            }
        }
        if(impossible)cout << "NO" << '\n';
        else cout << "YES" << '\n';
    }
    return 0;
}
