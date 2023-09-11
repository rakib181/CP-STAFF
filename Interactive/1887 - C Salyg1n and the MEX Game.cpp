#include<bits/stdc++.h>
using namespace std;
using ll = long long;

class Mex{
private:
    map<int, int> frequency;
    set<int> missing_number;
    vector<int> a;
public:
    explicit Mex(vector<int> const &a) : a(a){
        for(int i = 0; i <= (int) a.size(); i++){
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

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        Mex mx(a); int it = 2 * n + 1, mex = mx.MEX();
        while(it--){
            cout << mex << '\n';
            cout.flush();
            cin >> mex;
            if(mex < 0)break;
        }
    }
    return 0;
}
