#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 2e5 + 9;
vector<int> g[N], a(N);
set<int> se[N];

void DFS(int cur, int par){
    for(auto x : g[cur]){
        if(x != par){
            se[cur].insert(x);
            DFS(x, cur);
        }
    }
}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i ++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    DFS(1, 1);
    for(int i = 0; i < n; i++)cin >> a[i];
    if(a[0] != 1){
        cout << "NO" << '\n';
        return 0;
    }
    queue<int> q;
    q.push(1);
    int it = 1;
    while (!q.empty()){
        int node = q.front();
        q.pop();
        while (!se[node].empty()) {
            if (se[node].find(a[it]) == se[node].end()) {
                cout << "NO" << '\n';
                return 0;
            }
            se[node].erase(a[it]);
            q.push(a[it]);
            it++;
        }
    }
    cout << "YES" << '\n';
    return 0;
}
