#include<bits/stdc++.h>
using namespace std;

#define long long long

const int N = 3e5 + 9;
vector<double> mola;
vector<int> g[N], st(N), fn(N);

struct BIT {
    int n{};
    vector<double> tree;
    explicit BIT(int n) {
        this -> n = n;
        this -> tree.assign(n + 5, log(1));
    }

    double read(int i) {
        i++;
        double sum = 0;
        while (i > 0) {
            sum += tree[i];
            i -= i & -i;
        }
        return sum;
    }

    void update(int i, double val) {
        i++;
        while (i <= n) {
            tree[i] += val;
            i += i & -i;
        }
    }

    double query(int from, int to) {
        return read(to) - read(from - 1);
    }
};


int n, tme = 0;
void dfs(int u, int p){
    st[u] = tme++;
    for(auto v : g[u]){
        if(v == p)continue;
        dfs(v, u);
    }
    fn[u] = tme - 1;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    mola.assign(n , 1.0);
    dfs(0, -1);
    BIT fen(n + 1);
    cout << fixed << setprecision(10);
    int q;
    cin >> q;
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int x; double y;
            cin >> x >> y;
            x--;
            fen.update(st[x], -log10(mola[x]) + log10(y));
            mola[x] = y;
        }else{
            int x, y;
            cin >> x >> y;
            x--, y--;
            double ans = fen.query(st[x], fn[x]) - fen.query(st[y], fn[y]);
            if(ans >= 9.0)cout << "1000000000\n";
            else cout << pow(10, ans) << '\n';
        }
    }
    return 0;
}
