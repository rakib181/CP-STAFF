#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 5e5 + 9;
vector<int> g[N], rg[N], order;
vector<bool> vis(N);

void dfs(int cur){
    vis[cur] = true;
    for(auto x : g[cur]){
        if(!vis[x]){
            dfs(x);
        }
    }
    order.push_back(cur);
}

void dfs1(int cur, vector<int> &c){
    vis[cur] = true;
    c.push_back(cur);
    for(auto x : rg[cur]){
        if(!vis[x]){
            dfs1(x, c);
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u++, v++;
        g[u].push_back(v);
        rg[v].push_back(u);
    }
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    reverse(order.begin(), order.end());
    vis.assign(N, false);
    vector<int> cc[n + 2]; int c = 1;
    for(auto  x : order){
        if(!vis[x]){
            vector<int> ccc;
            dfs1(x, ccc);
            cc[c++] = ccc;
        }
    }
    cout << c - 1 << '\n';
    for(int i = 1; i < c; i++){
        cout << (int) cc[i].size() << ' ';
        for(auto  x : cc[i]){
            cout << x - 1 << ' ';
        }
        cout << '\n';
    }
    return 0;
}

// Tarjan's Algorithms
#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 5e5 + 9;
vector<int> g[N], in(N), low(N);
vector<bool> in_stack(N), vis(N);
stack<int> st; int timer = 1, scc = 0;
vector<int> ans[N];

void dfs(int cur){
    low[cur] = in[cur] = timer++;
    vis[cur] = true;
    in_stack[cur] = true;
    st.push(cur);
    for(auto x : g[cur]){
        if(!vis[x]){
            dfs(x);
            if(in_stack[x]){
                low[cur] = min(low[cur], low[x]);
            }
        }else{
            if(in_stack[x]){
                low[cur] = min(low[cur], in[x]);
            }
        }
    }
    if(in[cur] == low[cur]){
        scc += 1;
        int p;
        while (true){
            p = st.top();
            st.pop(); in_stack[p] = false;
            ans[scc].push_back(p);
            if(p == cur) break;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    cout << scc << '\n';
    for(int i = scc; i >= 1; i--){
        cout << (int) ans[i].size() << ' ';
        for(auto x : ans[i]){
            cout << x << ' ';
        }
        cout << '\n';
    }
    return 0;
}
