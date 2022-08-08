#include<bits/stdc++.h>
using namespace std;

struct point{
    int x, y;
    bool operator < (point p) const{
        if(x == p.x){
            return y < p.y;
        }
        return x < p.x;
    }
};

//Check whether three points are clockwise or anti-clockwise
bool cw(point p1, point p2, point p3){
    return (p2.y - p1.y) * (p3.x - p2.x) - (p3.y - p2.y) * (p3.x - p1.x) > 0;
}
bool acw(point p1, point p2, point p3){
    return (p2.y - p1.y) * (p3.x - p2.x) - (p3.y - p2.y) * (p3.x - p1.x) < 0;
}

//Graham Scan Algorithm
vector<point> convex_hull(vector<point> points, int n){
    if(n <= 2)return points;
    vector<point> up, down;
    point first = points[0], last = points.back();
    up.push_back(first); down.push_back(first);
    for(int i = 1; i < n; i++){
        if( i == points.size() - 1 || cw(first, points[i], last)){
            while(up.size() >= 2 && !cw(up[up.size() - 2], up[up.size() - 1], points[i])){
                up.pop_back();
            }
            up.push_back(points[i]);
        }
        if(i == points.size() - 1 || acw(first, points[i], last)){
            while(down.size() >= 2 && !acw(down[down.size() - 2], down[down.size() - 1], points[i])){
                down.pop_back();
            }
            down.push_back(points[i]);
        }
    }
    points.clear();
    int i = 0, j = 0;
    
    //Merge up and down vectors
    while(i < up.size() || j < down.size()){
        if(up[i].x == down[i].x && up[i].y == down[i].y){
            points.push_back(up[i]);
        }else{
            points.push_back(up[i]);
            points.push_back(down[i]);
        }
        i++, j++;
    }
    return points;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<point> ar(n);
    for(int i = 0; i < n; i++){
        cin >> ar[i].x >> ar[i].y;
    }
    sort(ar.begin(), ar.end());
    vector<point> CH = convex_hull(ar, n);

    for(auto x : CH){
        cout << x.x << ' ' << x.y << '\n';
    }
    return 0;
}
