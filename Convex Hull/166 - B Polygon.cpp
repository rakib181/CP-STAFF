#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct PT{
    ll x, y;
    bool operator < (PT other) const{
        if(x == other.x)return y < other.y;
        return x < other.x;
    }
    bool operator == (PT other) const{
        return x == other.x and y == other.y;
    }
};

bool cw(PT a, PT b, PT c) {
    return a.x * (c.y - b.y) + b.x * (a.y - c.y) + c.x * (b.y - a.y) >= 0;
}

bool ccw(PT a, PT b, PT c) {
    return a.x * (c.y - b.y) + b.x * (a.y - c.y) + c.x * (b.y - a.y) <= 0;
}

bool cll(PT a, PT b, PT c) {
    return a.x * (c.y - b.y) + b.x * (a.y - c.y) + c.x * (b.y - a.y) == 0;
}


vector<PT> CH(vector<PT> &a){
    int n = (int) a.size();
    if(n <= 2)return a;
    sort(a.begin(), a.end());
    vector<PT> st;
    vector<PT> up, down;
    up.emplace_back(a[0]);
    down.emplace_back(a[0]);
    PT first = a[0], last = a[n - 1];
    st.push_back(a[0]);
    for(int i = 1; i < n; i++){
        if(i == n - 1 or cw(first, a[i], last)){
            while((int) up.size() >= 2 and !cw(up[(int) up.size() - 2], up.back(), a[i])){
                up.pop_back();
            }
            up.emplace_back(a[i]);
        }
        if(i == n - 1 or ccw(first, a[i], last)){
            while((int) down.size() >= 2 and !ccw(down[(int) down.size() - 2], down.back(), a[i])){
                down.pop_back();
            }
            down.emplace_back(a[i]);
        }
    }
    a.clear();
    for(auto p : up){
        a.emplace_back(p);
    }
    for(auto p : down){
        a.emplace_back(p);
    }
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    vector<PT> ans((int) a.size());
    for(int i = 0; i < (int) a.size(); i++){
        ans[i] = {a[i].x, a[i].y};
    }
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<PT> a;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        PT x{};
        cin >> x.x >> x.y;
        a.emplace_back(x);
    }
    set<PT> se;
    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        PT x{};
        cin >> x.x >> x.y;
        a.emplace_back(x);
        se.insert(x);
    }
    bool possible = true;
    vector<PT> convex_hull = CH(a);
    for(auto p : convex_hull){
        if(se.find(p) != se.end()){
            possible = false;
        }
    }
    cout << (possible ? "YES\n" : "NO\n");
    return 0;
}
