#include<bits/stdc++.h>
using namespace std;
#define long long long int

const int N = 1e4 + 9;
vector<int> g[N], col(N);

bool dfs(int u, int c){
    col[u] = c;
    for(auto v : g[u]){
        if(!col[v]){
            bool res = dfs(v, c ^ 3);
            if(!res){
                return false;
            }
        }else if(col[u] == col[v]){
            return false;
        }
    }
    return true;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
            g[i].clear();
            col[i] = 0;
        }
        for(int i = 1; i <= m; i++){
            int u, v;
            cin >> u >> v;
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
        bool bipartite = dfs(1, 1);
        vector<int> c1, c2;
        for(int i = 1; i <= n; i++){
            if(col[i] == 1)c1.emplace_back(i);
            else c2.emplace_back(i);
        }
        if(bipartite){
            cout << "Bob" << endl;
            for(int i = 1; i <= n; i++) {
                int x, y;
                cin >> x >> y;
                if((x == 1 or y == 1) and !c1.empty()){
                    cout << c1.back() << ' ' << 1 << endl;
                    c1.pop_back();
                }else if((x == 2 or y == 2) and !c2.empty()){
                    cout << c2.back() << ' ' << 2 << endl;
                    c2.pop_back();
                }else{
                    if(!c1.empty()){
                        if((x == 1 or y == 1)){
                            cout << c1.back() << ' ' << 1 << endl;
                        }else{
                            cout << c1.back() << ' ' << 3 << endl;
                        }
                        c1.pop_back();
                    }else{
                        if((x == 2 or y == 2)){
                            cout << c2.back() << ' ' << 2 << endl;
                        }else{
                            cout << c2.back() << ' ' << 3 << endl;
                        }
                        c2.pop_back();
                    }
                }
            }
        }else{
            cout << "Alice" << endl;
            for(int i = 1; i <= n; i++){
                cout << 1 << ' ' << 2 << endl;
                int x, y;
                cin >> x >> y;
            }
        }
    }
    return 0;
}
