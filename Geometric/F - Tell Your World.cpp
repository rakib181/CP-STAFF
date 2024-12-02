#include <bits/stdc++.h>
using namespace std;

#define long long long

long slope(pair<long, long> a, pair<long, long> b, pair<long, long> c, pair<long, long> d){
    long x1 = a.first, y1 = a.second;
    long x2 = b.first, y2 = b.second;
    long x3 = c.first, y3 = c.second;
    long x4 = d.first, y4 = d.second;
    return x2 * y4 - x2 * y3 - x1 * y4 + x1 * y3 - x4 * y2 + x4 * y1 + x3 * y2 - x3 * y1;
}

bool check(vector<long> &y, int a, int b){
    int n = (int) y.size();
    vector<int> r;
    for(int i = 0; i < n; i++){
        if(slope(make_pair(a, y[a]), make_pair(b, y[b]), make_pair(a, y[a]), make_pair(i, y[i])) != 0){
            r.emplace_back(i);
        }
    }
    if(r.empty())return false;
    int i = r[0];
    for(auto j : r){
        if(slope(make_pair(a, y[a]), make_pair(b, y[b]), make_pair(i, y[i]), make_pair(j, y[j])) != 0){
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<long> y(n);
    for(int i = 0; i < n; i++){
        cin >> y[i];
        y[i]--;
    }
    if(check(y, 0, 1) or check(y, 0, 2) or check(y, 1, 2)){
        cout << "Yes\n";
        return 0;
    }
    cout << "No\n";
    return 0;
}
