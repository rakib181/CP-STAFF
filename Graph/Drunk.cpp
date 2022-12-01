#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int N = 20010;
vector<int> g[N];
vector<int> vis(N);

bool isCycle(int cur){
    vis[cur] = 1;
    for(auto x : g[cur]){
        if(!vis[x]){
           bool yo = isCycle(x);
           if(yo){
               return true;
           }
        }else if(vis[x] == 1){
            return true;
        }
    }
    vis[cur] = 2;
    return false;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt, idx = 1;
    cin >> tt;
    while (tt--) {
        cout << "Case " << idx++ << ": ";
        unordered_map<string, int> mp;
        int n, node = 1;
        cin >> n;
        for (int i = 0; i < n; i++) {
            string s, ss;
            cin >> s >> ss;
            if (!mp.count(s)) {
                mp[s] = node++;
            }
            if (!mp.count(ss)) {
                mp[ss] = node++;
            }
            g[mp[s]].push_back(mp[ss]);
        }
        node--;
        bool ok = false;
        for (int i = 1; i <= node; i++) {
            if (!vis[i]) {
                if (isCycle(i)) {
                    ok = true;
                    break;
                }
            }
        }
        if (ok)cout << "No" << '\n';
        else cout << "Yes" << '\n';
        for (int i = 0; i < N; i++) {
            g[i].clear();
            vis[i] = 0;
        }
        mp.clear();
    }
    return 0;
}
