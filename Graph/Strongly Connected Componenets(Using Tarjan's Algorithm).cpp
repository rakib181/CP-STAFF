#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 1e5 + 9;
map<int, vector<int>> g;
map<int, bool> in_stack, vis;
vector<int> in_time(N), low_time(N);
stack<int> st;
int timer = 1, scc = 0;

void dfs(int cur){
    vis[cur] = true;
    in_stack[cur] = true;
    st.push(cur);
    in_time[cur] = low_time[cur] = timer++;
    for(auto x : g[cur]){
        if(vis[x] and in_stack[x]){
            low_time[cur] = min(low_time[cur], in_time[x]);
        }else if(!vis[x]) {
                dfs(x);
                if (in_stack[x]) {
                    low_time[cur] = min(low_time[cur], low_time[x]);
                }
            }
    }
    if(in_time[cur] == low_time[cur]){
        scc++;
        cout << "SCC : " << scc << '\n';
        while(true){
            int xx = st.top();
            st.pop(); in_stack[xx] = false;
            cout << xx << ' ';
            if(cur == xx)break;
        }
        cout << '\n';
    }
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
            dfs(i);
        }
    }
    return 0;
}
