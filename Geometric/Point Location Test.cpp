#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        x2 -= x1;
        x3 -= x1;
        y2 -= y1;
        y3 -= y1;
        long long cross_product = 1LL * x2 * y3 - 1LL * x3 * y2;
        if(cross_product < 0)cout << "RIGHT\n";
        else if(cross_product > 0)cout << "LEFT\n";
        else cout << "TOUCH\n";
    }
    return 0;
}

//Better Solution
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
    ll cross_product(PT &other) const{
        return 1LL * x * other.y - 1LL * y * other.x;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        PT p1{}, p2{}, p3{};
        p1.read();
        p2.read();
        p3.read();
        p2 -= p1;
        p3 -= p1;
        ll prod = p2.cross_product(p3);
        if(prod < 0)cout << "RIGHT\n";
        else if(prod > 0)cout << "LEFT\n";
        else cout << "TOUCH\n";
    }
    return 0;
}
