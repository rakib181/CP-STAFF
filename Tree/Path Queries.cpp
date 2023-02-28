#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 2e5 + 10;
vector<int> g[N], ar(N), st(N), en(N); int timer = 1;

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
}FN;


void dfs(int cur, int par){
    st[cur] = timer++;
    for(auto x : g[cur]){
        if(x != par){
            dfs(x, cur);
        }
    }
    en[cur] = timer - 1;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    FN.init(n + 100);
    for(int i = 1; i <= n; i++){
        cin >> ar[i];
    }
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs(1, 0);
    for(int i = 1; i <= n; i++){
        FN.add(st[i], ar[i]);
        FN.add(en[i] + 1, -ar[i]);
    }
    while (q--){
        int type;
        cin >> type;
        if(type == 1){
            int i, v;
            cin >> i >> v;
            FN.add(st[i], v - ar[i]);
            FN.add(en[i] + 1, ar[i] - v);
            ar[i] = v;
        }else{
            int i;
            cin >> i;
            cout << FN.sum(st[i]) << '\n';
        }
    }
    return 0;
}
