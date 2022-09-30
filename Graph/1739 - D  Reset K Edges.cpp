#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
vector<int> g[N];
vector<int> height; int ops, limit;

void dfs(int cur, int par){
    height[cur] = 1;
    for(auto x : g[cur]){
        if(x != par){
            dfs(x, cur);
            height[cur] = max(height[cur], height[x] + 1);
        }
    }
    if(height[cur] >= limit and par > 1){
        ops++;
        height[cur] = 0;
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
        int n, k;
        cin >> n >> k;
        for(int i = 1; i <= n; i++)g[i].clear();
        for(int i = 2; i <= n; i++){
           int x;
           cin >> x;
           g[x].push_back(i);
           g[i].push_back(x);
        }
        int l = 1, r = n - 1, ans = 0;
        while(l <= r){
            limit = (l + r) >> 1;
            height.assign(n + 1, 0);
            ops = 0;
            dfs(1, -1);
            if(ops <= k){
                ans = limit;
                r = limit - 1;
            }else l = limit + 1;
        }
        cout << ans << '\n';
    }
    return 0;
}
