#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> f(int n){
    vector<int> p;
    for(int i = 2; 1LL * i * i <= n; i++){
        while(n % i == 0){
            p.emplace_back(i);
            n /= i;
        }
    }
    if(n > 1)p.emplace_back(n);
    return p;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    while(cin >> n >> m and !(n == 0 and m == 0)){
        map<int, int> c_n, c_m;
        for(int i = 2; i <= n; i++){
            vector<int> v = f(i);
            for(auto x : v){
                c_n[x] += 1;
            }
        }
        vector<int> v = f(m);
        for(auto x : v){
            c_m[x] += 1;
        }
        ll ans = 1;
        for(auto [x, y] : c_n){
            if(c_m[x] > y){
                ans = 0;
            }else{
                ans *= (y - c_m[x] + 1);
            }
        }
        for(auto [x, y] : c_m){
            if(y > c_n[x]){
                ans = 0;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
