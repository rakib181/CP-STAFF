#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 2e5 + 9;
vector<int> g[N], ind(N), p(N);

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, c = 1;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        ind[v] += 1;
    }
    queue<int> q; bool ok = true;
    for(int i = 1; i <= n; i++){
        if(ind[i] == 0){
            q.push(i);
        }
    }
    if((int) q.size() != 1)ok = false;
    if(ok){
        while (!q.empty()){
            if((int) q.size() != 1){
                ok = false;
                break;
            }
            int node = q.front();
            q.pop();
            p[node] = c++;
            for(auto x : g[node]){
                if(--ind[x] == 0){
                    q.push(x);
                }
            }
        }
    }
    if(ok){
       cout << "Yes" << '\n';
       for(int i = 1; i <= n; i++){
           cout << p[i] << ' ';
       }
    }else cout << "No" << '\n';
    return 0;
}
