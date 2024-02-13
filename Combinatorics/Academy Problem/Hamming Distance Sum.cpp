#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 9;
string s, t;
pair<int, int> p[N];

void cal(){
    for(int i = 0; i < (int) s.size(); i++){
        p[i] = {s[i] == '0', s[i] == '1'};
        if(i){
            p[i].first += p[i - 1].first;
            p[i].second += p[i - 1].second;
        }
    }
}

int get(int l, int r, int id){
    if(id == 0){
        return p[r].first - (l ? p[l - 1].first : 0);
    }else{
        return p[r].second - (l ? p[l - 1].second : 0);
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> t >> s;
    cal();
    int n = (int) s.size(), m = (int) t.size();
    ll ans = 0;
    for(int i = 0; i < m; i++){
        int l = i, r = m - i - 1;
        r = n - r - 1;
        int id = t[i] == '1' ? 0 : 1;
        ans += get(l, r, id);
    }
    cout << ans << '\n';
    return 0;
}