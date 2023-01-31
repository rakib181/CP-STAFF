#include <bits/stdc++.h>
using namespace std;

class Mex{
private:
    const int N = 2e5 + 9;
    map<int, int> frequency;
    set<int> missing_number;
public:
    Mex(){
        for(int i = 0; i < N; i++){
            missing_number.insert(i);
        }
    }
    void Add(int new_val){
        ++frequency[new_val];
        missing_number.erase(new_val);
    }
    int mex(){
        return *missing_number.begin();
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Mex mex;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        mex.Add(x);
        cout << mex.mex() << '\n';
    }
    return 0;
}
