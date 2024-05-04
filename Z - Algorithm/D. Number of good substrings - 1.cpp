#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> z_fun(string &s){
    int n = (int) s.size();
    vector<int> z(n, 0);
    for(int l = 0, r = 0, i = 1; i < n; ++i){
        if(i <= r)z[i] = min(z[i - l], r - i + 1);
        while(i + z[i] < n and s[i + z[i]] == s[z[i]] )++z[i];
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
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        string p;
        cin >> p;
        int m = (int) p.size();
        s = p + "$" + s;
        int n = (int) s.size();
        vector<int> z = z_fun(s);
        vector<int> seg; int cnt = 0, pat = 0;
        int i = m + 1; ll ans = 0;
        while(i < n){
            if(z[i] >= m) {
                pat += 1;
                seg.emplace_back(cnt + m - 1);
                cnt = 0;
            }else{
                cnt += 1;
            }
            i += 1;
        }
        if(cnt > 0){
            seg.emplace_back(cnt);
        }
        auto get = [](int n){
            return 1LL * n * (n + 1) / 2;
        };
        for(auto x : seg){
            ans += get(x);
        }
        if(pat){
            m -= 2;
            ans -= max(0LL, 1LL * pat * get(m));
        }
        cout << ans << '\n';
    }
    return 0;
}
