#include<bits/stdc++.h>
using namespace std;

#define int long long int

const int N = 2e5 + 9;
vector<int> g[N];
vector<int> sum (N, 0), L(N), R(N);
int ans;

void dfs(int cur, int par){
    for(auto x : g[cur]){
        if(x != par){
            dfs(x, cur);
        }
    }
    if(sum[cur] < L[cur]){
        ans++;
        sum[cur] = R[cur];
    }else if(sum[cur] > R[cur]){
        sum[cur] =  R[cur];
    }
    if(par != -1){
        sum[par] += sum[cur];
    }
}

int32_t main(){
    int tt;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++)g[i].clear(), L[i] = 0, R[i] = 0, sum[i] = 0;
        for (int i = 2; i <= n; i++) {
            int x;
            cin >> x;
            g[x].push_back(i);
            g[i].push_back(x);
        }
        for (int i = 1; i <= n; i++) {
            cin >> L[i] >> R[i];
        }
        ans = 0;
        dfs(1, -1);
        cout << ans << '\n';
    }
    return 0;
}
