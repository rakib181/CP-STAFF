#include<bits/stdc++.h>
using namespace std;

void prefix(string &s, vector<int> &pi){
   pi[0] = -1; int n = (int) s.size() ;
   for(int i = 1; i <= n; i++){
       int k = pi[i - 1];
       while (k >= 0 and s[k] != s[i - 1])k = pi[k];
       pi[i] = k + 1;
   }
}

void z_func(string &s, vector<int> &z){
    z[0] = 0;
    int l = 0, r = 0;
    for(int i = 1; i <= (int) s.size(); i++){
        if(r >= i) z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] - 1 < (int) s.size() and s[z[i]] == s[i + z[i]])z[i]++;
        if(i + z[i] - 1 > r)l = i, r = i + z[i] - 1;
    }
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string pat;
    cin >> pat;
    int n = (int) pat.size();
    vector<int> pi(n + 1), z(n + 1);
    prefix(pat, pi);
    z_func(pat, z);
    for(int i = 0; i < n; i++){
        cout << z[i] << ' ';
    }
    cout << '\n';
    for(int i = 1; i <= n; i++){
        cout << pi[i] << ' ';
    }
    return 0;
}
