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
string s, p;
string f(string x, string y){
    string copy = x;
    int n = (int) x.size();
    x += "$" + y;
    vector<int> z = z_fun(x);
    int m = (int) y.size(), N = (int) x.size();
    int skip = 0;
    for(int i = n + 1; i < N; i++){
        if(z[i] + i == N){
            skip = max(skip, z[i]);
        }
    }
    if(!skip)return copy + y;
    else return y + copy.substr(skip);
}

bool fun(string x, string y){
    int m = (int) x.size();
    x += "$" + y;
    vector<int> z = z_fun(x);
    for(int i = m + 1; i < (int) x.size(); i++){
        if(z[i] >= m){
            return true;
        }
    }
    return false;
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        cin >> s >> p;
        if(fun(s, p) or fun(p, s)) {
            if((int) s.size() > (int) p.size()){
                cout << s << '\n';
            }else{
                cout << p << '\n';
            }
        }else {
            string ans = s + p;
            string f1 = f(s, p);
            string f2 = f(p, s);
            if ((int) ans.size() > (int) f1.size()) {
                ans = f1;
            }
            if ((int) ans.size() > (int) f2.size()) {
                ans = f2;
            }
            cout << ans << '\n';
        }
    }
    return 0;
}
