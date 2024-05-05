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
    string s, p;
    cin >> s >> p;
    string a = p + "$" + s;
    reverse(p.begin(), p.end());
    string b = p + "$" + s;
    vector<int> z_a = z_fun(a);
    vector<int> z_b = z_fun(b);
    int n = (int) s.size(), res = -1;
    for(int i = 0; i <= n; i++){
        if((i == n or z_a[n + i + 1] == n - i) and z_b[n + 1] >= i){
            res = i;
            break;
        }
    }
    if(res == -1){
        cout << "No\n";
    }else{
        cout << "Yes\n" << res << '\n';
    }
    return 0;
}
