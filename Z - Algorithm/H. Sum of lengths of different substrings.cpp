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

ll cal(string s){
    vector<int> z = z_fun(s);
    int i = *max_element(z.begin(), z.end());
    ll sum = 0;
    i += 1;
    while(i <= (int) s.size()){
        sum += i;
        i += 1;
    }
    return sum;
}

signed main(){
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   string s;
   cin >> s;
   int n = (int) s.size();
   ll ans = 0;
   for(int i = n - 1; i >= 0; i--){
       ans += cal(s.substr(i));
   }
   cout << ans << '\n';
}
