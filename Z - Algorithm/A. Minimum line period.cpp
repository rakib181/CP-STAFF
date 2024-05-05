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
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        vector<int> z = z_fun(s);
        int n = (int) s.size(), res = -1;
        for (int i = 1; i < n; i++) {
            if (i + z[i] == n) {
                res = i;
                break;
            }
        }
        if (res == -1) {
            cout << s << '\n';
        } else {
            cout << s.substr(0, res) << '\n';
        }
    }
    return 0;
}
