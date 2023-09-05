#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 1e12;
vector<ll> s;
void cal(){
    ll x = 1;
    int y = 2;
    while(x <= N){
        s.emplace_back(x);
        x *= y;
        y += 1;
    }
}

int f(ll n){
    int size = (int) s.size();
    int ans = INT_MAX;
    for(int mask = 0; mask < (1 << size); mask++){
        ll sum = 0; int cnt = 0;
        for(int i = 0; i < size; i++){
            if((mask >> i) & 1){
                sum += s[i];
                cnt += 1;
            }
        }
        ans = min(ans, cnt + __builtin_popcountll(n - sum));
    }
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cal();
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        cout << f(n) << '\n';
    }
    return 0;
}
