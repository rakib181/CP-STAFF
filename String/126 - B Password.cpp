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
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string pat;
    cin >> pat;
    int n = (int) pat.size();
    vector<int> pi(n + 1);
    prefix(pat, pi); int idx = 0;
    for(int i = 1; i < n; i++){
        if(pi[i] == pi[n] or pi[i] == pi[pi[n]]){
            idx = max(idx, pi[i]);
        }
    }
    cout << (idx ? pat.substr(0, idx) : "Just a legend");
    return 0;
}
