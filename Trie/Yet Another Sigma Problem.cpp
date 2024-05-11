#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 3e5 + 9;

struct Trie{
    vector<vector<int>> trans;
    vector<int> count;
    int n, cnt;
    explicit Trie(){
        this -> n = N;
        this -> cnt = 0;
        this -> count.assign(N, 0);
        this -> trans.assign(N, vector<int> (26, -1));
    }
    void insert(string &s){
        int now = 0;
        for(auto c : s){
            int tr = c - 'a';
            if(trans[now][tr] == -1){
                trans[now][tr] = ++cnt;
            }
            now = trans[now][tr];
            count[now] += 1;
        }
    }

    ll query(string &s){
        int now = 0; ll ans = 0;
        for(auto c : s){
            int tr = c - 'a';
            if(trans[now][tr] == -1){
                return ans;
            }
            now = trans[now][tr];
            ans += count[now];
        }
        return ans;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    Trie trie;
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        string s;
        cin >> s;
        ans += trie.query(s);
        trie.insert(s);
    }
    cout << ans << '\n';
    return 0;
}
