#include<bits/stdc++.h>
using namespace std;
#define long long long int

const int N = 2e5 + 9;
vector<int> d[N];
int mobius[N];

void cal(){
    mobius[1] = 1;
    for(int i = 2; i < N; i++){
        mobius[i]--;
        for(int j = i + i; j < N; j += i){
            mobius[j] -= mobius[i];
        }
    }
    for(int i = 1; i < N; i++){
        for(int j = i; j < N; j += i){
            d[j].emplace_back(i);
        }
    }
}
int cnt[N];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cal();
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        for(auto v : d[x]){
            cnt[v]++;
        }
    }
    while(q--){
        int x;
        cin >> x;
        int ans = 0;
        for(auto v : d[x]){
            ans += mobius[v] * cnt[v];
        }
        assert(ans <= n);
        cout << ans << '\n';
    }
    return 0;
}
