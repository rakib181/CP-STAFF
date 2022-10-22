#include<bits/stdc++.h>
using namespace std;

#define int long long int

class GRAPH{
public:
    int n{};
    vector<pair<int, int>> *g{};
    vector<int> lvl;
    vector<int> path;
    void INIT(int _n){
        this -> n = _n;
        this -> g = new vector<pair<int, int>> [n];
    }

    void ADDEDGE(int u, int v, int wt) const{
        g[u].emplace_back(v, wt);
    }

    bool BFS(int dis, int _n, int d){
        queue<int> q;
        lvl.assign(n, INT_MAX);
        path.assign(n, INT_MAX);
        lvl[1] = 0;
        path[1] = 0;
        q.push(1);
        while(!q.empty()){
            int node =  q.front();
            q.pop();
            for(auto x : g[node]){
                if(x.second <= dis and lvl[x.first] == INT_MAX){
                    q.push(x.first);
                    lvl[x.first] = lvl[node] + 1;
                    path[x.first] = node;
                    if(x.first == _n){
                        return lvl[x.first] <= d;
                    }
                }
            }
        }
          return false;
    }
    void PATH(int dest){
        stack<int> st;
        cout << lvl[dest] << '\n';
        int s = dest;
        while(s != 0){
            st.push(s);
            s = path[s];
        }
        while(!st.empty()){
            cout << st.top() << ' ';
            st.pop();
        }
    }
}G;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, d;
    cin >> n >> m >> d;
    G.INIT(n + 1);
    for(int i = 0; i < m; i++){
        int u, v, wt;
        cin >> u >> v >> wt;
        G.ADDEDGE(u, v, wt);
    }
    int l = 0, r = 1e9, ans = 0;
    while(l <= r){
        int mid = (l + r) >> 1LL;
        if(G.BFS(mid, n, d)){
            ans = mid;
            r = mid - 1;
        }else l = mid + 1;
    }
    if(r == 1e9)cout << "-1" << '\n';
    else {
        G.BFS(ans, n, d);
        G.PATH(n);
    }
    return 0;
}
