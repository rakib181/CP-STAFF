#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 2e5 + 9;
vector<int> g[N];
vector<int> a(N), b(N), ans(N), dex; int s, ss;

void DFS(int cur, int par){
    s += a[cur];
    ss += b[cur];
    dex.push_back(ss);
    int l = 0, r = (int) dex.size() - 1, idx = r;
    while (l <= r){
        int m = (l + r) >> 1;
        if(dex[m] <= s){
            idx = m;
            l = m + 1;
        }else r = m - 1;
    }
    ans[cur] = idx;
    for(auto x : g[cur]){
        if(x != par){
            DFS(x, cur);
        }
    }
    s -= a[cur];
    ss -= b[cur];
    dex.pop_back();
}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--){
        int n;
        cin >> n;
        for(int i = 0; i <= n; i++){
            g[i].clear();
        }
        dex.clear();
        a.clear();
        b.clear();
        ans.clear();
        for(int i = 2; i <= n; i++){
            int u, w, x;
            cin >> u >> w >> x;
            g[u].emplace_back(i);
            a[i] = w;
            b[i] = x;
        }
        s = 0, ss = 0;
        DFS(1, -1);
        for(int i = 2; i <= n; i++){
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
