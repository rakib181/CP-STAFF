#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
vector<int> d[N], all[N];
int mul[N];

void cal(){
    for(int i = 1; i < N; i++){
        for(int j = i; j < N; j += i){
            d[j].emplace_back(i);
        }
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cal();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n + 1];
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        for(int i = 0; i < N; i++){
            mul[i] = 0;
            all[i].clear();
        }
        for(int i = 1; i <= n; i++){
            for(auto x : d[a[i]]){
                all[x].emplace_back(i);
            }
        }
        auto f = [&](vector<int> &g){
            int sz = (int) g.size();
            ll sum = 0;
            for(int i = 0; i < sz; i++){
                sum += 1LL * i * (n - g[i]);
            }
            return sum;
        };
        ll ans = 0;
        for(int i = 1; i < N; i++){
            int need = i;
            for(auto x : d[i]){
                if(i == x)continue;
                need -= mul[x];
            }
            ans += 1LL * need * f(all[i]);
            mul[i] = need;
        }
        cout << ans << '\n';
    }
    return 0;
}
