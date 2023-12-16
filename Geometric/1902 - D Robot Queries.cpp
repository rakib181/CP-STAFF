#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct PT{
    int x{}, y{};
    PT()= default;
    PT(int x, int y){
        this -> x = x;
        this -> y = y;
    }
    PT operator + (PT other) const{
        return {x + other.x, y + other.y};
    }
    PT operator - (PT other) const{
        return {x - other.x, y - other.y};
    }
    bool operator < (PT other) const{
        if(x == other.x){
            return y < other.y;
        }
        return x < other.x;
    }
};


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<PT> pos;
    map<PT, vector<int>> cnt;
    pos.emplace_back(0, 0);
    PT cur = {0, 0};
    cnt[cur].emplace_back(0);
    for(int i = 0; i < n; i++){
        if(s[i] == 'R'){
            cur.x += 1;
        }else if(s[i] == 'L'){
            cur.x -= 1;
        }else if(s[i] == 'U'){
            cur.y += 1;
        }else cur.y -= 1;
        pos.emplace_back(cur);
        cnt[cur].emplace_back(i + 1);
    }
    while(q--){
        int x, y, l, r;
        cin >> x >> y >> l >> r;
        if(cnt.count(PT(x, y))){
            int fst = cnt[PT(x, y)][0];
            int lst = cnt[PT(x, y)].back();
            if(fst <= l - 1 or lst > r){
                cout << "YES\n";
                continue;
            }
        }
        PT need = pos[r] + pos[l - 1] - PT(x, y);
        if(cnt.count(need)){
            auto idx = lower_bound(cnt[need].begin(), cnt[need].end(), l - 1) - cnt[need].begin();
            if(idx < (int) cnt[need].size() and cnt[need][idx] >= l - 1 and cnt[need][idx] <= r - 1){
                cout << "YES\n";
            }else cout << "NO\n";
        }else cout << "NO\n";
    }
    return 0;
}
