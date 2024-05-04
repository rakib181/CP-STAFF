#include<bits/stdc++.h>
using namespace std;
using ll = long long;


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        string rev = s;
        int m = (int) s.size();
        reverse(rev.begin(), rev.end());
        s += "$" + rev;
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
        int mx = 0;
        for (int i = m; i < n; i++) {
           if(i + z[i] == n) mx = max(mx, z[i]);
        }
        cout << mx << '\n';
    }
    return 0;
}
