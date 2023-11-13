#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct Trie{
    Trie *bit[2]{};
    int cnt;
    Trie(){
        cnt = 0;
        bit[0] = nullptr;
        bit[1] = nullptr;
    }
    void insert(int x, int b = 30){
        int ith = (x >> b) & 1;
        cnt += 1;
        if(bit[ith] == nullptr){
            bit[ith] = new Trie();
        }
        if(b >= 0) bit[ith] -> insert(x, b - 1);
    }

    ll query(int x, int lim, int b = 30){
        int x_b = (x >> b) & 1, lim_b = (lim >> b) & 1, xor_b = ((lim ^ x) >> b) & 1;
        ll res = 0;
        if(lim_b and bit[x_b]){
            res += bit[x_b] -> cnt;
        }
        if(bit[xor_b]){
            res += bit[xor_b] ->query(x, lim, b - 1);
        }
        return res;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n, u, v;
        cin >> n >> u >> v;
        ll ans = 0;
        Trie trie;
        for(int i = 1; i <= n; i++){
            int val;
            cin >> val;
            ans += (trie.query(val, v + 1) - trie.query(val, u));
            trie.insert(val);
        }
        cout << ans << '\n';
    }
    return 0;
}
