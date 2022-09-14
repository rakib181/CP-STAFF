#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
vector<int> g[N];
vector<bool> vis(N, false), rflag(N, false);
stack<int> st;
 
bool dfs(int cur){
    vis[cur] = true;
    st.push(cur);
    rflag[cur] = true;
    for(auto x : g[cur]){
        if(!vis[x]){
            if(dfs(x)) return true;
        }else if(rflag[x]){
            st.push(x);
            return true;
        }
    }
    rflag[cur] = false;
    st.pop();
    return false;
}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            if(dfs(i))break;
        }
    }
    if(st.empty())cout << "IMPOSSIBLE" << '\n';
    else{
        vector<int> ans;
        int tmp = st.top();
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
            if(ans.back() == tmp and ans.size() != 1){
                break;
            }
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << '\n';
        for(auto x : ans){
            cout << x << ' ';
        }
        cout << '\n';
    }
    return 0;
}
