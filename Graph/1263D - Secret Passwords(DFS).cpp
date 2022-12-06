#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 26;
vector<int> g[N];
vector<bool> vis(N);

void DFS(int cur){
    vis[cur] = true;
    for(auto x : g[cur]){
        if(!vis[x]){
            DFS(x);
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(auto x: s){
            g[i].push_back(x - 'a' + n);
            g[x - 'a' + n].push_back(i);
        }
    }
    int cc = 0;
    for(int i = n; i < n + 26; i++){
        if(!vis[i] and !g[i].empty()){
            DFS(i);
            cc++;
        }
    }
    cout << cc << '\n';
    return 0;
}
