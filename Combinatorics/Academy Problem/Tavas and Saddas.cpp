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
    vector<int> ans;
    auto f = [&](string s){
        do{
            ans.emplace_back(stoi(s));
        }while(next_permutation(s.begin(), s.end()));
    };
    for(int d = 1; d <= 9; d++){
        string s, t;
        for(int i = 1; i <= d; i++){
            s = string(i, '4') + string(d - i, '7');
            t = string(d - i, '4') + string(i, '7');
            f(s);
            f(t);
        }
    }
    sort(ans.begin(), ans.end());
    ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
    int n;
    cin >> n;
    for(int i = 0; i < (int) ans.size(); i++){
        if(ans[i] == n){
            cout << i + 1 << '\n';
            break;
        }
    }
    return 0;
}