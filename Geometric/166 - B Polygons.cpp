#include<bits/stdc++.h>
using namespace std;

struct Point {
    long long x, y;
    bool operator < (Point P) const {
        if (x == P.x) return y < P.y;
        else return x < P.x;
    }
    bool operator == (Point P) const {
        return (x == P.x && y == P.y);
    }
};
bool cw(Point a, Point b, Point c) {
    long long x1 = a.x * (c.y - b.y), y1 = b.x * (a.y - c.y), z1 = c.x * (b.y - a.y);
    bool ok = false;
    if(x1 + y1 + z1 < 0){
        ok = true;
    }
    return ok;
}
bool ccw(Point a, Point b, Point c) {
    long long x1 = a.x * (c.y - b.y), y1 = b.x * (a.y - c.y), z1 = c.x * (b.y - a.y);
    bool ok = false;
    if(x1 + y1 + z1 > 0){
        ok = true;
    }
    return ok;
}
bool cll(Point a, Point b, Point c) {
    long long x1 = a.x * (c.y - b.y), y1 = b.x * (a.y - c.y), z1 = c.x * (b.y - a.y);
    bool ok = false;
    if(x1 == 0 && y1 == 0 && z1 == 0){
        ok = true;
    }
    return ok;
}
vector<Point> convex_hull(vector<Point> points) {
    if (points.size() <= 2) return points;
    sort(points.begin(), points.end());
    vector<Point> up, down;
    Point first = points[0], last = points.back();
    up.push_back(first); down.push_back(first);
    for (int i = 1; i < points.size(); i++) {
        if (i == points.size() - 1 || !ccw(first, points[i], last)) {
            while (up.size() >= 2 && ccw(up[up.size() - 2], up[up.size() - 1], points[i])) {
                up.pop_back();
            }
            up.push_back(points[i]);
        }
        if (i == points.size() - 1 || !cw(first, points[i], last)) {
            while (down.size() >= 2 && cw(down[down.size() - 2], down[down.size() - 1], points[i])) {
                down.pop_back();
            }
            down.push_back(points[i]);
        }
    }
    points.clear();
    for (int i = 0; i < up.size(); i++) {
        points.push_back(up[i]);
    }
    for (int i = 0; i < down.size(); i++) {
        points.push_back(down[i]);
    }
    sort(points.begin(), points.end());
    points.resize(unique(points.begin(), points.end()) - points.begin());
    return points;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<Point> convex;
    vector<Point> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].x >> a[i].y;
        convex.push_back(a[i]);
    }
    int m;
    cin >> m;
    vector<Point> b(m);
    for(int i = 0; i < m; i++){
        cin >> b[i].x >> b[i].y;
        convex.push_back(b[i]);
    }
    sort(convex.begin(), convex.end());
    vector<Point> CH = convex_hull(convex);
    set<Point> se;
    bool ok = true;
    for(auto x : CH){
        se.insert(x);
    }
    for(int i = 0 ; i < m; i++){
        if(se.find(b[i]) != se.end()){
            ok = false;
            break;
        }
    }
    if(ok)cout << "YES" << '\n';
    else cout << "NO" << '\n';
    return 0;
}
