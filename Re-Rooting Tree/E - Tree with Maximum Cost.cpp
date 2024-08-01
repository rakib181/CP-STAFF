#include<bits/stdc++.h>
using namespace std;

#define long long long int

const int N = 3e5 + 9;
vector<int> g[N], a(N);
vector<long> sum(N);
long cost = 0, ans = 0;
int n;

void dfs(int u, int p, int depth){
    cost += 1LL * a[u] * depth;
    sum[u] = a[u];
    for(auto v : g[u]){
        if(v != p){
            dfs(v, u, depth + 1);
            sum[u] += sum[v];
        }
    }
}


void reroot(int u, int p){
    ans = max(ans, cost);
    for(auto v : g[u]){
        if(v != p){
            long sub_sum = sum[v];
            long remaining_sum = sum[1] - sub_sum;
            cost -= sub_sum;
            cost += remaining_sum;
            reroot(v, u);
            cost += sub_sum;
            cost -= remaining_sum;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs(1, 0, 0);
    reroot(1, 0);
    cout << ans << '\n';
    return 0;
}
