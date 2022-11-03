#include <bits/stdc++.h>
using namespace std;

#define int long long int

class Kosa_Raju{
public:
    int n;
    vector<int> *g, *trans;
    vector<bool> vis;
    explicit Kosa_Raju(int _n){
        this -> n = _n;
        this -> g = new vector<int> [n];
        this -> trans = new vector<int> [n];
        vis.resize(n, false);
    }

    void add_edge(int u, int v, bool m_g) const{
        if(m_g){
            g[u].push_back(v);
        }else{
            trans[u].push_back(v);
        }
    }

    void topological(int cur, stack<int> &st){
        vis[cur] = true;
        for(auto x : g[cur]){
            if(!vis[x]){
                topological(x, st);
            }
        }
        st.push(cur);
    }

    void trans_pose(){
        for(int i = 1; i <= n - 1; i++){
            vis[i] = false;
            for(auto x : g[i]){
                add_edge(x, i, false);
            }
        }
    }

    void dfs(int cur, vector<int> &ans, int scc){
        vis[cur] = true;
        ans[cur] = scc;
        for(auto x : trans[cur]){
            if(!vis[x]){
                dfs(x, ans, scc);
            }
        }
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> coins(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> coins[i];
    }
    Kosa_Raju KR(n + 1);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        KR.add_edge(u, v, true);
    }
    stack<int> st;
    for(int i = 1; i <= n; i++){
        if(!KR.vis[i]){
            KR.topological(i, st);
        }
    }
    KR.trans_pose();
    int scc = 0;
    vector<int> ans(n + 1);
    while (!st.empty()){
        int node = st.top();
        st.pop();
        if(!KR.vis[node]){
            KR.dfs(node, ans, ++scc);
        }
    }
    vector<int> sum(n + 1, 0);
    for(int i = 1; i <= n; i++){
        sum[ans[i]] += coins[i];
    }
    for(int i = 1; i <= n; i++){
        KR.vis[i] = false;
    }
    for(int i = 1; i <= n; i++){
        if(!KR.vis[i]){
            KR.topological(i, st);
        }
    }
    set<int> chk[n + 1];
    for(int i = 1; i <= n; i++){
        for(auto x : KR.g[i]){
            if(ans[i] != ans[x])chk[ans[i]].insert(ans[x]);
        }
    }
    for(int i = 1; i <= n; i++){
        KR.vis[i] = false;
    }
    stack<int> v;
    while (!st.empty()){
        int node = st.top();
        st.pop();
        if(!KR.vis[ans[node]])v.push(ans[node]), KR.vis[ans[node]] = true;
    }
    int mx = 0;
    while(!v.empty()){
        int node = v.top();
       // cout << node << ' ';
        v.pop();
        int tmp_mx = sum[node];
        for(auto x : chk[node]){
            tmp_mx = max(tmp_mx, sum[node] + sum[x]);
        }
        sum[node] = tmp_mx;
    }
    cout << *max_element(sum.begin() + 1, sum.begin() + scc) << '\n';
    return 0;
}
