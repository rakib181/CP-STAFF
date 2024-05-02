#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct PT{
    int x, y;
    void read(){
        cin >> x >> y;
    }
    PT operator - (PT &other) const{
        return {x - other.x, y - other.y};
    }
    void operator -= (PT &other){
        x -= other.x;
        y -= other.y;
    }
    ll operator *(PT other) const{
        return 1LL * x * other.y - 1LL * other.x * y;
    }
    ll triangle(PT &a, PT &b) {
        return (a - *this) * (b - *this);
    }
};


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<PT> a(n);
    for(int i = 0; i < n; i++){
        a[i].read();
    }
    ll area = 0; PT x = {0, 0};
    for(int i = 0; i < n; i++){
        area += x.triangle(a[i], a[(i + 1) % n]);
    }
    cout << abs(area) << '\n';
    return 0;
}
