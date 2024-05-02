#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const ll inf = 3'000'000'001LL;

struct PT{
    ll x, y;
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
        return x * other.y - other.x * y;
    }
    ll triangle(PT &a, PT &b) {
        return (a - *this) * (b - *this);
    }
};

bool intersect(PT p1, PT p2, PT p3, PT p4){
    if((p2 - p1) * (p4 - p3) == 0){
        if(p1.triangle(p2, p3) != 0){
            return false;
        }
        for(int i = 0; i < 2; i++){
            if(max(p1.x, p2.x) < min(p3.x, p4.x) or max(p1.y, p2.y) < min(p3.y, p4.y)){
                return false;
            }
            swap(p1, p3);
            swap(p2, p4);
        }
        return true;
    }
    for(int i = 0; i < 2; i++){
        ll sign1 = (p2 - p1) * (p3 - p1);
        ll sign2 = (p2 - p1) * (p4 - p1);
        if((sign1 < 0 and sign2 < 0) or (sign1 > 0 and sign2 > 0)){
            return false;
        }
        swap(p1, p3);
        swap(p2, p4);
    }
    return true;
}

bool is_contains(PT a, PT b, PT c){
    if(a.triangle(b, c) != 0)return false;
    return (min(a.x, c.x) <= b.x and b.x <= max(a.x, c.x) and min(a.y, c.y) <= b.y and b.y <= max(a.y, c.y));
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<PT> a(n); ll area = 0;
    for(int i = 0; i < n; i++){
        a[i].read();
    }
    /* Pick's Theorem : Area = Interior + Boundary / 2 - 1
     * => 2 * Area = 2 * Interior + Boundary - 2
     * => 2 * Interior = 2 * Area - Boundary + 2
     * => Interior = (2 * Area - Boundary + 2) / 2
     */

    ll boundary = 0, interior = 0; PT x = {0, 0};
    for(int i = 0; i < n; i++){
        PT diff = a[i] - a[(i + 1) % n];
        area += x.triangle(a[i], a[(i + 1) % n]);
        long long g = __gcd(abs(diff.x), abs(diff.y));
        boundary += g;
    }
    interior = (abs(area) - boundary + 2) / 2;
    cout << interior << ' ' << boundary << '\n';
    return 0;
}
