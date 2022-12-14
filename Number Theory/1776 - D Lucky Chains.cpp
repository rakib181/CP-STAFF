#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 1e7 + 5;
vector<int> spf(N);

void  SPF(){
    for(int i = 2; i < N; i++){
        spf[i] = i;
    }
    for(int i = 4; i < N; i += 2){
        spf[i] = 2;
    }
    for(int i = 2; i * i < N; i++){
        if(spf[i] == i){
            for(int j = 2 * i; j < N; j += i){
                spf[j] = min(spf[j], i);
            }
        }
    }
}

set<int> genPrime(int x){
    set<int> st;
    while(x > 1){
        st.insert(spf[x]);
        x /= spf[x];
    }
    return st;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    SPF();
    int tt;
    cin >> tt;
    while (tt--) {
       int x, y;
       cin >> x >> y;
       if(__gcd(x, y) > 1) {
           cout << "0" << '\n';
           continue;
       }
       int gap = y - x;
       if(gap == 1){
           cout << "-1" << '\n';
           continue;
       }
       set<int> st = genPrime(gap);
       int ans = INT_MAX;
       for(auto xx : st){
           ans = min(ans, (x / xx + 1) * xx);
       }
       cout << ans - x << '\n';
    }
    return 0;
}
