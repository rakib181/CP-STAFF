#include<bits/stdc++.h>
using namespace std;
#define int long long int

const int N = 2e5 + 9;
vector<int> g[N];
vector<bool> vis(N);

void AddEdge(int u, int v){
    g[u].push_back(v);
    g[v].push_back(u);
}

void DFS(int cur, vector<int> &comp){
    vis[cur] = true;
    comp.push_back(cur);
    for(auto x : g[cur]){
        if(!vis[x]){
            DFS(x, comp);
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        for(int i = 0; i < n; i++){
            if(i < n - i - 1)AddEdge(i, n - i - 1);
            if(i + k < n)AddEdge(i, i + k);
        }
        int ans = n, no_need = 0;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                vector<int> comp;
                DFS(i, comp);
                vector<int> cnt(26, 0);
                for(auto x : comp){
                    cnt[s[x] - 'a']++;
                }
                no_need += *max_element(cnt.begin(), cnt.end());
            }
        }
        cout << ans - no_need << '\n';
        for(int i = 0; i < n; i++){
            g[i].clear();
            vis[i] = false;
        }
    }
    return 0;
}
