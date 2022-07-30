#include <bits/stdc++.h>
using namespace std;

struct point{
    int x, y;
};

int orientation(point p1, point p2, point p3){
    int val = (p3.x  - p2.x) * (p2.y - p1.y) - (p2.x - p1.x) * (p3.y - p2.y);
    if(val == 0) return 0;
    return (val > 0) ? 1 : 2;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    point p1 = {1, 2}, p2 = {4,4}, p3 ={0, 0};
    int ans = orientation(p1, p2, p2);
    cout << ans << '\n';
    if(ans == 0)cout << "Collinear !" << '\n';
    else if(ans == 1)cout << "Clockwise !" << '\n';
    else if (ans == 2) cout << "Anti-clockwise !" << '\n';
    return 0;
}
