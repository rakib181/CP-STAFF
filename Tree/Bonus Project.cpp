#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 1e6 + 10;
vector<int> g[N], a(N), st(N), en(N); int timer;

struct fenwick
{
    vector<int> fn;
    int n{};
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
    int tt;
    cin >> tt;
    while (tt--) {
        int n, q; timer = 1;
        cin >> n >> q;
        for(int i = 0; i <= n; i++){
            g[i].clear();
            st[i] = en[i] = a[i] = 0;
        }
        FN.init(n + 100);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
        dfs(1, 0);
        vector<pair<int, int>> Q;
        for(int i = 0; i < q; i++){
            int id, val;
            cin >> id >> val;
            a[id] += val;
            Q.emplace_back(id, val);
        }
        for(auto x : Q){
            int i = x.first, v = x.second;
            FN.add(st[i], v);
            FN.add(en[i] + 1, -v);
        }
        for(int i = 1; i <= n; i++){
            cout << FN.sum(st[i]) + a[i] << ' ';
        }
        cout << '\n';
        FN.fn.clear();
    }
    return 0;
}
