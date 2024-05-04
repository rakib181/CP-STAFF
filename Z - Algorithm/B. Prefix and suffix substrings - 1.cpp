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

vector<int> prefix(string &s){
    int n = (int) s.size();
    vector<int> p(n, 0);
    p[0] = -1;
    for(int i = 1; i < n; i++){
        int k = p[i - 1];
        while(k >= 0 and s[i - 1] != s[k])k = p[k];
        p[i] = k + 1;
    }
    return p;
}

int f(string &s, vector<bool> &ps){
    int ans = 0;
    int n = (int) s.size();
    vector<int> p = prefix(s);
    for(int i = 0; i < n; i++){
        int k = i;
        while(k >= 0){
            if(!ps[k])ans += 1;
            k = p[k];
        }
    }
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int n = (int) s.size();
        vector<bool> ps(n + 1, false);
        vector<int> z = z_fun(s);
        ps[0] = true;
        for(int i = n - 1; i >= 0; i--){
            if(z[i] == n - i){
                ps[n - i] = true;
            }
        }
        int ans = f(s, ps);
        reverse(s.begin(), s.end());
        ans += f(s, ps);
        cout << ans << '\n';
    }
    return 0;
}
