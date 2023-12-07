#include<bits/stdc++.h>
using namespace std;
using ll = long long;

class DSU{
public:
    vector<int> P, SZ;
    void init(int n){
        P.assign(n, 0);
        SZ.assign(n, 1);
        iota(P.begin(), P.end(), 0);
    }

    int FIND(int v){
        if(P[v] == v)return v;
        return P[v] = FIND(P[v]);
    }

    void UNION(int u, int v){
        u = FIND(u), v = FIND(v);
        if(u == v)return;

        if(SZ[u] > SZ[v]){
            swap(u, v);
        }
        P[v] = u;
        SZ[u] += SZ[v];
    }
}DS;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<bool> vis(26, false);
        vector<int> which(26, -1);
        DS.init(26);
        string ans;
        for(int i = 0; i < n; i++){
            if(which[s[i] - 'a'] != -1){
                ans += char(which[s[i] - 'a'] + 'a');
                continue;
            }
            for(int c = 'a'; c <= 'z'; c++){
                if(vis[c - 'a']) continue;
                if((DS.FIND(s[i] - 'a') == DS.FIND(c - 'a')) and DS.SZ[DS.FIND(s[i] - 'a')] < 26)continue;
                vis[c - 'a'] = true;
                ans += char(c);
                which[s[i] - 'a'] = c - 'a';
                DS.UNION(s[i] - 'a', c - 'a');
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
