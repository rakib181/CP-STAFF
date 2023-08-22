#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 9;
bitset<N> p;
int pos[7] = {1, 10, 100, 1000, 10000, 100000, 1000000};

int len(int n){
    int c = 0;
    while(n){
        c += 1;
        n /= 10;
    }
    return c;
}
void cal(){
    p[0] = p[1] = true;
    for(int i = 4; i < N; i += 2)p[i] = true;
    for(int i = 3; i < N; i += 2){
        if(!p[i]){
            for(int j = i + i; j < N; j += i){
                p[j] = true;
            }
        }
    }
}

int ith(int n, int k){
    return (n / pos[k]) % 10;
}

int dijkstra(int s, int target){
    vector<int> vis(N, INT_MAX);
    priority_queue<pair<int, int>> pq;
    vis[s] = 0; int sz = len(s);
    pq.push({-vis[s], s});
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        if(node == target)return vis[node] + s;
        for(int i = 0; i < sz; i++){
            int d = ith(node, i);
            if(d != 0){
                int v = node - pos[i];
                if(p[v]){
                    if(vis[v] > vis[node] + v){
                        vis[v] = vis[node] + v;
                        pq.push({-vis[v], v});
                    }
                }
            }
            if(d != 9){
                int v = node + pos[i];
                if(p[v]){
                    if(vis[v] > vis[node] + v){
                        vis[v] = vis[node] + v;
                        pq.push({-vis[v], v});
                    }
                }
            }
        }
    }
    return -1;
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cal();
    int t, cs = 1;
    cin >> t;
    while(t--){
        cout << "Case " << cs++ << ": ";
        int a, b;
        cin >> a >> b;
        cout << dijkstra(a, b) << '\n';
    }
    return 0;
}
