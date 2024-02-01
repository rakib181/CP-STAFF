#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

int bin(int x, int y){
    int ans = 1;
    while(y){
        if(y & 1)ans = 1LL * ans * x % mod;
        x = 1LL * x * x % mod;
        y >>= 1;
    }
    return ans;
}

vector<int> lps(string &s){
    int n = (int) s.size();
    vector<int> p(n + 1, 0);
    p[0] = -1;
    for(int i = 1; i <= n; i++){
        int k = p[i - 1];
        while(k >= 0 and s[i - 1] != s[k]) k = p[k];
        p[i] = k + 1;
    }
    return p;
}

int match(string s, string p){
      int m = (int) p.size();
      p = p + "$" + s;
      int n = (int) p.size();
      vector<int> pi = lps(p);
      int cnt = 0;
      for(int i = 0; i <= n; i++){
          if(pi[i] == m)cnt += 1;
      }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        string rev = s;
        reverse(rev.begin(), rev.end());
        string new_s = s + rev;
        int pw = bin(2, k - 1);
        int ans = 1LL * pw * match(new_s, s) % mod;
        pw = ((pw - 1) % mod + mod) % mod;
        new_s.clear();
        new_s = rev + s;
        new_s.erase(new_s.begin());
        new_s.pop_back();
        ans += 1LL * pw * match(new_s, s) % mod;
        ans %= mod;
        cout << ans << '\n';
    }
    return 0;
}
