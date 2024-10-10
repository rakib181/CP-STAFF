#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
vector<int> g[N], a(N), ans(N);

map<int, int> dfs(int u, int p, int prev_sum){
    map<int, int> freq;
    int s = prev_sum + a[u];
    for(auto v : g[u]){
        if(v == p)continue;
        map<int, int> new_freq = dfs(v, u, s);
        if(new_freq.size() > freq.size())swap(new_freq, freq);
        for(auto [x, y] : new_freq){
            freq[x] += y;
        }
    }
    ans[u] = freq[prev_sum];
    freq[s]++;
    return freq;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] == 0)a[i] = -1;
    }
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs(1, 0, 0);
    while (q--){
        int u;
        cin >> u;
        cout << ans[u] << '\n';
    }
    return 0;
}
