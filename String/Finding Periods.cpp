#include<bits/stdc++.h>
using namespace std;

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
    vector<int> z(n + 1);
    z_func(pat, z);
    for(int i = 0; i < n; i++){
        if(i + z[i] >= n)cout << i << ' ';
    }
    cout << n << '\n';
    return 0;
}
