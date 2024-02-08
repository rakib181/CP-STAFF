#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 9;
int p[6][N];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q, id = 0;
    cin >> n >> q;
    string s;
    cin >> s;
    string t = "abc";
    do{
        string x;
        while((int) x.size() < n){
            x += t;
        }
        for(int i = 0; i < n; i++){
            p[id][i] = (x[i] != s[i]);
            if(i)p[id][i] += p[id][i - 1];
        }
        id += 1;
    }while (next_permutation(t.begin(), t.end()));
    const int inf = 1e9;
    auto f = [&](int id, int l, int r){
        return p[id][r] - (l ? p[id][l - 1] : 0);
    };
    auto get = [&](int l, int r){
        int ans = inf;
        for(int i = 0; i < id; i++){
            ans = min(ans, f(i, l, r));
        }
        return ans;
    };
    while(q--){
        int l, r;
        cin >> l >> r;
        l -= 1, r -= 1;
        cout << get(l, r) << '\n';
    }
    return 0;
}