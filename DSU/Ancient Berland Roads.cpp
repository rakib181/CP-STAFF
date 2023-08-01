#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 5e5 + 9;
int p[N], sz[N];
ll population[N];
stack<int> st[N];
multiset<ll> ms;

void init(int n){
    for(int i = 1; i < n; i++){
        p[i] = i, sz[i] = 1;
        population[i] = st[i].top();
        ms.insert(population[i]);
    }
}

int f(int u){
    if(p[u] == u)return u;
    return p[u] = f(p[u]);
}

void uni(int u, int v){
    u = f(u), v = f(v);
    if(sz[u] < sz[v])swap(u, v);
    if(u != v){
        ms.erase(ms.find(population[u]));
        ms.erase(ms.find(population[v]));
        p[v] = u;
        sz[u] += sz[v];
        population[u] += population[v];
        ms.insert(population[u]);
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        st[i].push(x);
    }
    vector<pair<int, int>> edge;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        edge.emplace_back(u,v);
    }
    vector<pair<int, pair<int, int>>> queries;
    vector<bool> destroyed(m + 2, false);
    for(int i = 0; i < q; i++){
        char type;
        cin >> type;
        if(type == 'D'){
            int k;
            cin >> k;
            k -= 1;
            destroyed[k] = true;
            queries.push_back({0, {k, -1}});
        }else{
            int a, x;
            cin >> a >> x;
            st[a].push(x);
            queries.push_back({1, {a, x}});
        }
    }
    init(n + 1);
    for(int i = 0; i < m; i++){
        if(!destroyed[i]){
            uni(edge[i].first, edge[i].second);
        }
    }
    vector<ll> ans;
    ans.emplace_back(*ms.rbegin());
    for(int i = (int) queries.size() - 1; i >= 0; i--){
        int type = queries[i].first;
        if(type == 0){
           int idx = queries[i].second.first;
           int u = edge[idx].first;
           int v = edge[idx].second;
           uni(u, v);
        }else{
            int u = queries[i].second.first;
            ms.erase(ms.find(population[f(u)]));
            int old_population = st[u].top();
            population[f(u)] -= old_population;
            st[u].pop();
            int new_population = st[u].top();
            population[f(u)] += new_population;
            ms.insert(population[f(u)]);
        }
        if(i)ans.emplace_back(*ms.rbegin());
    }
    reverse(ans.begin(), ans.end());
    for(auto x : ans){
        cout << x << '\n';
    }
    return 0;
}
