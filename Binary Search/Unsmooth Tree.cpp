#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 9;
const double inf = 1e15, eps = 1e-7;
int n;
vector<int> g[N];
double x, a[N];
pair<double, double> range[N];

bool invalid(pair<double, double> &p){
    if(p.first >= -inf and p.first <= p.second and p.second <= inf)return false;
    return true;
}

pair<double, double> intersect(pair<double, double> p, pair<double, double> q){
        if(invalid(p) or invalid(q)){
            return {inf, -inf};
        }
        p.first = max(p.first, q.first);
        p.second = min(p.second, q.second);
        if(invalid(p))return {inf, -inf};
        return p;
}

pair<double, double> unite(pair<double, double> p){
    if(invalid(p))return {inf, -inf};
    p.first -= x;
    p.second += x;
    p.first = max(-inf, p.first);
    p.second = min(inf, p.second);
    if(invalid(p))return {inf, -inf};
    return p;
}


void dfs(int u, int p){
    if(a[u] == inf){
        range[u] = {-inf, inf};
    }else{
        range[u] = {a[u], a[u]};
    }
    for(auto v : g[u]){
        if(v != p){
            dfs(v, u);
            range[u] = intersect(range[u], unite(range[v]));
        }
    }
}


bool f(double val){
    x = val;
    dfs(1, 0);
    for(int i = 1; i <= n; i++){
        if(invalid(range[i])){
            return false;
        }
    }
    return true;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i = 1; i <= n; i++){
        string s;
        cin >> s;
        if(s == "*"){
            a[i] = inf;
        }else {
            a[i] = stoi(s);
        }
    }
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    double l = 0, r = 1e12;
    while((r - l) > eps){
        double m = (l + r) / 2;
        if(f(m)){
            r = m;
        }else{
            l = m;
        }
    }
    cout << fixed << setprecision(6) << r << '\n';
    return 0;
}
