#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> z_fun(string &s){
    int n = (int) s.size();
    vector<int> z(n, 0);
    for(int l = 0, r = 0, i = 1; i < n; ++i){
        if(i <= r)z[i] = min(z[i - l], r - i + 1);
        while(i + z[i] < n && s[z[i]] == '?' or s[i + z[i]] == s[z[i]] )++z[i];
        if(i + z[i] - 1 > r){
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        string p;
        cin >> p;
        int m = (int) p.size();
        s = p + "$" + s;
        int n = (int) s.size();
        vector<int> ans;
        vector<int> z = z_fun(s);
        for(int i = m + 1; i < n; i++){
            if(z[i] == m){
                ans.emplace_back(i - m - 1);
            }
        }
        cout << (int) ans.size() << '\n';
        for(auto x : ans){
            cout << x << ' ';
        }
        cout << '\n';
    }
    return 0;
}
