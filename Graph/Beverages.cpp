#include <bits/stdc++.h>
using namespace std;
const int N = 105;
vector<int> g[N]; vector<int> ind(N);
map<string, int> mp; map<int, string> mpp;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, cs = 1;
    while (cin >> n){
        for(int i = 0; i < N; i++){
            g[i].clear();
            ind[i] = 0;
        }
        mp.clear();
        mpp.clear();
        int node = 1;
        for(int i = 0; i < n; i++){
            string s;
            cin >> s;
            if(!mp[s]){
                mpp[node] = s;
                mp[s] = node;
                node += 1;
            }
        }
        int m;
        cin >> m;
        for(int i = 0; i < m; i++){
            string s, ss;
            cin >> s >> ss;
                g[mp[s]].push_back(mp[ss]);
                ind[mp[ss]] += 1;
        }
        vector<string> a;
        priority_queue<int, vector<int>, greater<int>> q;
        for(int i = 1; i < node; i++){
            if(!ind[i]){
                q.push(i);
            }
        }
        while (!q.empty()){
            int nod = q.top();
            q.pop();
            a.push_back(mpp[nod]);
            for(auto x : g[nod]){
                if(--ind[x] == 0){
                    q.push(x);
                }
            }
        }
        cout << "Case #" << cs++ << ": Dilbert should drink beverages in this order: ";
        for(int i = 0; i < (int) a.size(); i++){
            cout << a[i] << " ."[i == (int)a.size() - 1];
        }
        cout << "\n\n";
    }
    return 0;
}
