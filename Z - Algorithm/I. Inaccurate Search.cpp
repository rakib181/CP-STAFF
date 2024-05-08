#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> z_fun(string s){
    int n = (int) s.size();
    vector<int> z(n, 0);
    for(int i = 1, l = 0, r = 0; i < n; i++){
        if(i <= r){
            z[i] = min(z[i - l], r - i + 1);
        }
        while(i + z[i] < n and s[z[i]] == s[i + z[i]]){
            z[i] += 1;
        }
        if(i + z[i] - 1 > r){
            l = i, r = i + z[i] - 1;
        }
    }
    return z;
}

signed main(){
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   string s, p; int k;
   cin >> s >> p >> k;
   string a = p + "$" + s;
   reverse(s.begin(), s.end());
   reverse(p.begin(), p.end());
   string b = p + "$" + s;
   vector<int> z_a = z_fun(a);
   vector<int> z_b = z_fun(b);
   int n = (int) a.size(), m = (int) p.size();
   vector<int> ans;
   for(int i = m + 1; i + m - 1 < n; i++){
       if(z_a[i] + k >= m){
           ans.emplace_back(i - m);
       }else if(z_a[i] + z_b[n - i + 1] + k >= m){
           ans.emplace_back(i - m);
       }
   }
   cout << (int) ans.size() << '\n';
   for(auto x : ans){
       cout << x << ' ';
   }
   cout << '\n';
   return 0;
}
