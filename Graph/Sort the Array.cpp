#include<bits/stdc++.h>
using namespace std;
#define int long long int
map<int, int> g, vis;

int DFS(int cur){
    vis[cur] = 1;
    int cnt = 0;
    if(vis[g[cur]] == 0){
            int sub = DFS(g[cur]) + 1;
            cnt += sub;
    }
    return cnt;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--){
        int n;
        cin >> n;
        g.clear();
        vis.clear();
        vector<int> a(n), b(n);
        for(int i = 0; i < n; i++)cin >> a[i], b[i] = a[i];
        sort(b.begin(), b.end());
        for(int i = 0; i < n; i++){
           g[a[i]] = b[i];
           vis[a[i]] = 0;
        }
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(vis[a[i]] == 0){
                cnt += DFS(a[i]);
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}
