#include<bits/stdc++.h>
using namespace std;

struct bit{
    int n{};
    vector<int> fn;
    explicit bit(int n){
        this -> n = n;
        fn.assign(n + 5, 0);
    }
    void add(int i, int v){
        while (i <= n){
            fn[i] += v;
            i += i & -i;
        }
    }
    int query(int i){
        int s = 0;
        while (i > 0){
            s += fn[i];
            i -= i & -i;
        }
        return s;
    }
};



int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<array<int, 3>> a;
    set<int> se;
    for(int i = 0; i < n; i++){
        int _, x, y;
        cin >> _ >> _ >> x >> y;
        a.push_back({x, y, -1});
        se.insert(x);
        se.insert(y);
    }
    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        int x, y;
        cin >> x >> y;
        a.push_back({x, y, i});
        se.insert(x);
        se.insert(y);
    }
    map<int, int> mp;
    int id = 0;
    for(auto x : se){
        mp[x] = ++id;
    }
    bit fn(id + 5);
    vector<int> ans(q);
    sort(a.begin(), a.end());
    for(int i = 0; i < (int) a.size(); i++){
        if(a[i][2] == -1){
            fn.add(mp[a[i][1]], 1);
        }else{
            ans[a[i][2]] = fn.query(mp[a[i][1]]);
        }
    }
    for(int i = 0; i < q; i++){
        cout << ans[i] << '\n';
    }
    return 0;
}
