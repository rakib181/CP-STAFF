#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 26;
vector<vector<int>> g(N, vector<int> (N));
vector<bool> used(N);

void DFS(int cur){
    if(used[cur])return;
    used[cur] = true;
    for(int i = 0; i < N; i++){
        if(g[cur][i]){
            DFS(i);
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--){
        for(int i = 0; i < N; i++){
            g[i].clear();
            used[i] = false;
        }
        int n;
        cin >> n;
        vector<int> in(N), out(N);
        for(int i = 0; i < n; i++){
            string s;
            cin >> s;
            int u = s[0] - 'a', v = s[(int) s.size() - 1] - 'a';
            g[u][v]++;
            in[v]++;
            out[u]++;
        }
        int src, cnt_src = 0, cnt_des = 0, cnt = 0;
        for(int i = 0; i < N; i++){
            if(in[i] + 1 == out[i]){
                src = i;
                cnt_src++;
            }else if(in[i] == out[i] + 1){
                cnt_des++;
            }else{
                if(in[i] != out[i]){
                    cnt++;
                }
            }
        }
        bool ok = false;
        if(cnt_src == 1 and cnt_des == 1 and cnt == 0){
            ok = true;
            DFS(src);
            for(int i = 0; i < N; i++){
                if(in[i] != 0 or out[i] != 0){
                    if(!used[i]){
                        ok = false;
                        break;
                    }
                }
            }
        }else if(cnt_src == 0 and cnt_des == 0 and cnt == 0){
            ok = true;
            for(int i = 0; i < N; i++){
                if(in[i]){
                    src = i;
                }
            }
            DFS(src);
            for(int i = 0; i < N; i++){
                if(in[i] != 0 or out[i] != 0){
                    if(!used[i]){
                        ok = false;
                        break;
                    }
                }
            }
        }else{
            ok = false;
        }
        if(ok) cout << "Ordering is possible." << '\n';
        else cout << "The door cannot be opened." << '\n';
    }
    return 0;
}
