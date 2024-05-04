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
    while(t--){
        int n, l, r;
        cin >> n >> l >> r;
        string s;
        cin >> s;
        vector<int> z = z_fun(s);
        z[0] = n;
        int eps =  int(ceil(sqrt(n)));
        vector<int> ans(n + 1, 0);
        auto f = [&](int len, int k){
            int cnt = 1;
            int i = len;
            while(i < n){
                if(z[i] >= len){
                    cnt += 1;
                    i += len;
                }else{
                    i += 1;
                }
            }
            return cnt >= k;
        };
        for(int k = 1; k <= eps; k++){
            int L = 1, R = n, val = 0;
            while(L <= R){
                int M = (L + R) >> 1;
                if(f(M, k)){
                    val = M;
                    L = M + 1;
                }else{
                    R = M - 1;
                }
            }
            ans[k] = val;
        }
        for(int len = 1; len <= eps; len++){
            int k = 1;
            int i = len;
            while(i < n){
                if(z[i] >= len){
                    k += 1;
                    i += len;
                }else{
                    i += 1;
                }
            }
            ans[k] = max(ans[k], len);
        }
        for(int i = n - 1; i >= 0; i--){
            ans[i] = max(ans[i], ans[i + 1]);
        }
        for(int i = l; i <= r; i++){
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
