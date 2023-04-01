#include<bits/stdc++.h>
using namespace std;
#define int long long int

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    string s, ans; cin >> s; set<char> se;
    ans.resize(k);
    for(auto x : s){
        se.insert(x);
    }
    auto smallest_char = *se.begin();
    if(k <= n){
        for(int i = k - 1; i >= 0; i--){
            auto it = se.upper_bound(s[i]);
            if(it != se.end()){
                auto next_large = *it;
                for(int j = 0; j < i; j++){
                    ans[j] = s[j];
                }
                ans[i] = next_large;
                for(int j = i + 1; j < k; j++){
                    ans[j] = smallest_char;
                }
                break;
            }
        }
        cout << ans << '\n';
    }else{
        int i;
        for(i = 0; i < n; i++){
            ans[i] = s[i];
        }
        while (i < k){
            ans[i++] = smallest_char;
        }
        cout << ans << '\n';
    }
    return 0;
}
