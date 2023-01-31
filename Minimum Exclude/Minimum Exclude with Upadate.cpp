#include <bits/stdc++.h>
using namespace std;

class Mex{
private:
    map<int, int> frequency;
    set<int> missing_number;
    vector<int> a;
public:
    explicit Mex(vector<int> const &a) : a(a){
        for(int i = 0; i < (int) a.size(); i++){
            missing_number.insert(i);
        }
        for(auto x : a){
            ++frequency[x];
            missing_number.erase(x);
        }
    }
    void UPDATE(int idx, int new_val){
        if(--frequency[a[idx]] == 0){
            missing_number.insert(a[idx]);
        }
        a[idx] = new_val;
        ++frequency[new_val];
        missing_number.erase(new_val);
    }
    int MEX(){
        return *missing_number.begin();
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    Mex mex(a);
    int m;
    cin >> m;
    while (m--){
        int type;
        cin >> type;
        if(type) {
            int idx, v;
            cin >> idx >> v;
            mex.UPDATE(idx, v);
        }else{
            cout << mex.MEX() << '\n';
        }
    }
    return 0;
}
