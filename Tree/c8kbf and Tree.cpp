#include<bits/stdc++.h>
using namespace std;
#define int long long int

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--){
        int n;
        cin >> n;
        vector<pair<int, int>> g[n + 1];
        for(int i = 0; i < n - 1; i++){
            int u, v, w;
            cin >> u >> v >> w;
            g[u].emplace_back(v, w);
            g[v].emplace_back(u, w);
        }
        vector<int> pref(n + 1, -1);
        pref[1] = 0;
        queue<int> q;
        q.push(1);
        while (!q.empty()){
            int node = q.front();
            q.pop();
            for(auto x : g[node]){
                if(pref[x.first] == -1){
                    pref[x.first] = pref[node] ^ x.second;
                    q.push(x.first);
                }
            }
        }
        map<int, pair<int, int>> used; bool found = false;
        for(int i = 1; i <= n; i++){
            for(int j = i + 1; j <= n; j++){
                int need = pref[i] ^ pref[j];
                if(used.find(need) == used.end()){
                    used[need] = {i, j};
                }else{
                    found = true;
                    auto it = used[need];
                    cout << it.first << ' ' << it.second << ' ' << i << ' ' << j << '\n';
                    break;
                }
            }
            if(found) break;
        }
        if(!found) cout << "-1" << '\n';
    }
    return 0;
}
