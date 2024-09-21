#include<bits/stdc++.h>
using namespace std;

#define long long long
mt19937 mt(time(nullptr));

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
        int n, q;
        cin >> n >> q;
        map<long, long> id;
        vector<long> a(n + 1);
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            if(!id.count(a[i])){
                id[a[i]] = mt();
            }
        }
        for(int i = 1; i <= n; i++){
            a[i] = id[a[i]];
            a[i] ^= a[i - 1];
        }
        auto get = [&](int l, int r){
            return a[r] ^ a[l - 1];
        };
        while(q--){
            int l, r;
            cin >> l >> r;
            if(get(l, r) == 0){
                cout << "YES\n";
            }else{
                cout << "NO\n";
            }
        }
    }
    return 0;
}
