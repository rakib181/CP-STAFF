#include <bits/stdc++.h>
using namespace std;

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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
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
    cout << scc << '\n';
    for(int i = 1; i <= n; i++){
        cout << ans[i] << ' ';
    }
    return 0;
}
