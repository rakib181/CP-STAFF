#include<bits/stdc++.h>
using namespace std;
using ll = long long;


vector<int> z_fun(string &s){
    int n = (int) s.size();
    vector<int> z(n, 0);
    for(int l = 0, r = 0, i = 1; i < n; ++i){
        if(i <= r)z[i] = min(z[i - l], r - i + 1);
        while(i + z[i] < n && s[i + z[i]] == s[z[i]])++z[i];
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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> z = z_fun(s);
    int len = 1;
    while(len + z[len] < n and s[len + z[len]] <= s[z[len]]){
        len += 1;
    }
    string x = s.substr(0, min(len, k));
    string ans = x;
    int i = 0, sz = (int) ans.size();
    while((int) ans.size() < k){
        ans += x[i % sz];
        i += 1;
    }
    cout << ans << '\n';
    return 0;
}
