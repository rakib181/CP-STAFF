#include<bits/stdc++.h>
using namespace std;

struct PT{
    int x, y;
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


vector<vector<int>> CH(vector<vector<int>> &point){
    int n = (int) point.size();
    if(n <= 2)return point;
    vector<PT> a(n);
    for(int i = 0; i < n; i++){
        int x = point[i][0], y = point[i][1];
        a[i] = {x, y};
    }
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
    vector<vector<int>> ans((int) a.size(), vector<int> (2));
    for(int i = 0; i < (int) a.size(); i++){
        ans[i][0] = a[i].x;
        ans[i][1] = a[i].y;
    }
    return ans;
}

vector<vector<int>> outerTrees(vector<vector<int>> &trees) {
    return CH(trees);
}

signed main(){
    vector<vector<int>> c = {
            {1, 1}, {2, 2}, {2, 0}, {2, 4}, {3, 3}, {4, 2}
    };
    vector<vector<int>> ans = outerTrees(c);
    for(int i = 0; i < (int) ans.size(); i++){
        cout << ans[i][0] << ' ' << ans[i][1] << '\n';
    }
}
