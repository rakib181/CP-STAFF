#include<bits/stdc++.h>
using namespace std;
#define int long long int

const int N = 1e5 + 9;
vector<int> Z(N), prefix_sum(N);

void z_algorithm(string &s){
    int n = (int) s.size();
    Z[0] = n; int l = 0, r = 0;
    for(int i = 1; i < n; i++){
        if(r >= i)Z[i] = min(r - i + 1, Z[i - l]);
        while (i + Z[i] < n and s[Z[i]] == s[i + Z[i]])Z[i]++;
        if(i + Z[i] - 1 > r) l = i, r = i + Z[i] - 1;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    z_algorithm(s);
    for(int i = 0; i < (int) s.size(); i++){
        if(Z[i]){
            prefix_sum[1]++;
            prefix_sum[Z[i] + 1]--;
        }
    }
    for(int i = 1; i <= (int) s.size(); i++){
        prefix_sum[i] += prefix_sum[i - 1];
    }
    vector<pair<int, int>> ans;
    for(int i = (int) s.size() - 1; i >= 0; i--){
        if(Z[i] == (int) s.size() - i){
            ans.emplace_back((int) s.size() - i, prefix_sum[Z[i]]);
        }
    }
    cout << (int) ans.size() << '\n';
    for(auto x : ans){
        cout << x.first << ' ' << x.second << '\n';
    }
    return 0;
}
