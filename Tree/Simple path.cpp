#include<bits/stdc++.h>
using namespace std;
#define int long long int

const int N = 2e5 + 9;
vector<int> g[N]; stack<int> path; bool done = false;

void dfs(int cur, int par, int des){
    if(!done){
        path.push(cur);
    }
    if(cur == des) done = true;
    for(auto x : g[cur]){
        if(x != par){
            dfs(x, cur, des);
        }
    }
    if(!done) path.pop();
}

void P(stack<int> &st){
    if(st.empty())return;
    int x = st.top();
    st.pop();
    P(st);
    cout << x << ' ';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, s, d;
    cin >> n >> s >> d;
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(s, -1, d);
    P(path);
    return 0;
}
