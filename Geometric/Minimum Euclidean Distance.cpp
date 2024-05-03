#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct PT{
    ll x{}, y{};
    void read(){
        cin >> x >> y;
    }
    bool operator < (const PT &other) const{
        if(x == other.x)return y < other.y;
        return x < other.x;
    }
};

ll euclid_distance(PT x, PT y){
    return (x.x - y.x) * (x.x - y.x) + (x.y - y.y) * (x.y - y.y);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<PT> a(n);
    for(int i = 0; i < n; i++){
        a[i].read();
    }
    ll min_distance = LLONG_MAX;
    sort(a.begin(), a.end());
    set<PT> se;
    se.insert({a[0].y, a[0].x});
    int j = 0;
    for(int i = 1; i < n; i++){
        ll dd = ceil(sqrt(min_distance));
        while(j < i and a[j].x < a[i].x - dd){
            se.erase({a[j].y, a[j].x});
            j += 1;
        }
        auto lower = se.lower_bound({a[i].y - dd, 0});
        auto upper = se.upper_bound({a[i].y + dd, 0});
        for(auto iter = lower; iter != upper; iter++){
            min_distance = min(min_distance, euclid_distance({iter -> y, iter -> x}, a[i]));
        }
        se.insert({a[i].y, a[i].x});
    }
    cout << min_distance << '\n';
    return 0;
}
