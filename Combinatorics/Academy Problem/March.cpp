#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    map<char, int> cnt;
    for(int i = 1; i <= n; i++){
        string s;
        cin >> s;
        cnt[s[0]] += 1;
    }
    ll ans = 0;
    vector<char> a({'M', 'A', 'R', 'C', 'H'});
    for(int i = 0; i < 5; i++){
        for(int j = i + 1; j < 5; j++){
            for(int k = j + 1; k < 5; k++){
                ans += 1LL * cnt[a[i]] * cnt[a[j]] * cnt[a[k]];
            }
        }
    }
    cout << ans << '\n';
    return 0;
}