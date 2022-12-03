#include<bits/stdc++.h>
using namespace std;

int n, ans = 0;
const int N = 2e5 + 9;
vector<int> g[N];
vector<int> color(N);

void DFS(int cur, int parent){
    if(color[cur] != color[parent])ans++;
    for(auto x : g[cur]){
        if(x != parent){
            DFS(x, cur);
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i = 2; i <= n; i++){
        int v;
        cin >> v;
        g[v].push_back(i);
        g[i].push_back(v);
    }
    for(int i = 1; i <= n; i++){
        cin >> color[i];
    }
    ans= 0;
    DFS(1, 0);
    cout << ans << '\n';
    return 0;
}
