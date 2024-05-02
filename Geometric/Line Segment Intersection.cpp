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

void solve(PT &p1, PT &p2, PT &p3, PT &p4){
    if((p2 - p1) * (p4 - p3) == 0){
        if(p1.triangle(p2, p3) != 0){
            cout << "NO\n";
            return;
        }
        for(int i = 0; i < 2; i++){
            if(max(p1.x, p2.x) < min(p3.x, p4.x) or max(p1.y, p2.y) < min(p3.y, p4.y)){
                cout << "NO\n";
                return;
            }
            swap(p1, p3);
            swap(p2, p4);
        }
        cout << "YES\n";
        return;
    }
    for(int i = 0; i < 2; i++){
        ll sign1 = (p2 - p1) * (p3 - p1);
        ll sign2 = (p2 - p1) * (p4 - p1);
        if((sign1 < 0 and sign2 < 0) or (sign1 > 0 and sign2 > 0)){
            cout << "NO\n";
            return;
        }
        swap(p1, p3);
        swap(p2, p4);
    }
    cout << "YES\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        PT p1{}, p2{}, p3{}, p4{};
        p1.read();
        p2.read();
        p3.read();
        p4.read();
        solve(p1, p2, p3, p4);
    }
    return 0;
}
