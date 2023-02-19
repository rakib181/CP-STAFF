#include <bits/stdc++.h>
using namespace std;
#define int long long int

class Mex{
private:
    map<int, int> frequency;
    set<int> missing_number;
    vector<int> a;
public:
    int n = 3e5 + 9;
    explicit Mex(vector<int> const &a) : a(a){
        for(int i = 0; i < n; i++){
            missing_number.insert(i);
        }
        for(auto x : a){
            ++frequency[x];
            missing_number.erase(x);
        }
    }
    int MEX(){
        return *missing_number.begin();
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n  >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    unique(a.begin(), a.end());
    vector<int> ok(k);
    for(int i = 0; i < k; i++){
        ok[i] = a[i];
    }
    Mex mx(ok);
    cout << mx.MEX() << '\n';
    return 0;
}
