#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define long long long


struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

gp_hash_table<long, int, custom_hash> s1, s2;
const int N = 2e5 + 9;
vector<int> d[N];

void cal(){
    for(int i = 1; i < N; i++){
        for(int j = i; j < N; j += i){
            d[j].emplace_back(i);
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cal();
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++)cin >> a[i];
    for(int i = 0; i < m; i++)cin >> b[i];
    long sa = accumulate(a.begin(), a.end(), 0LL);
    long sb = accumulate(b.begin(), b.end(), 0LL);
    for(int i = 0; i < n; i++){
        s1[sa - a[i]]++;
    }
    for(int i = 0; i < m; i++){
        s2[sb - b[i]]++;
    }
    while (q--){
        int x;
        cin >> x;
        bool f = false;
        if(x < 0){
            for(auto d1 : d[abs(x)]){
                int d2 = abs(x) / d1;
                if(s1[-d1] and s2[d2]){
                    f = true;
                }
                if(s1[d1] and s2[-d2]){
                    f = true;
                }
            }
        }else{
            for(auto d1 : d[x]){
                int d2 = x / d1;
                if(s1[-d1] and s2[-d2]){
                    f = true;
                }
                if(s1[d1] and s2[d2]){
                    f = true;
                }
            }
        }
        cout << (f ? "YES\n" : "NO\n");
    }
    return 0;
}
