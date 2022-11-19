#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 2e5 + 10;
vector<int> g[N];
vector<int> in(N), out(N), value(N); int timer = 0;

struct fenwick
{
    vector<int> fn;
    int n;
    void init(int _n){
        this -> n = _n;
        fn.resize(this -> n,0);
    }
    void add(int x,int val){
        while(x < n){
            fn[x] += val;
            x += x & (-x);
        }
    }
    int sum(int x){
        int sum = 0;
        while(x){
            sum += fn[x];
            x -= x & (-x);
        }
        return sum;
    }
    int sum(int l, int r){
        return sum(r) - sum(l - 1);
    }
}FN;

void dfs(int cur, int par){
    in[cur] = ++timer;
    FN.add(in[cur], value[cur]);
    for(auto x : g[cur]){
        if(x != par){
            dfs(x, cur);
        }
    }
    out[cur] = timer;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    FN.init(n + 100);
    for(int i = 1; i <= n; i++)cin >> value[i];
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs(1, 0);
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int i, x;
            cin >> i >> x;
            FN.add(in[i], -value[i]);
            value[i] = x;
            FN.add(in[i], +value[i]);
        }else{
            int x;
            cin >> x;
            cout << FN.sum(in[x], out[x]) << '\n';
        }
    }
    return 0;
}
