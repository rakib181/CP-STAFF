#include <bits/stdc++.h>
using namespace std;
const int MX = 1e5 + 9;
int a[MX];
class Mex{
private:
    set<int> missing_number;
public:
    explicit Mex(int n){
        for(int i = 1; i < MX; i++){
            missing_number.insert(i);
        }
        for(int i = 1; i <= n; i++){
            missing_number.erase(a[i]);
        }
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
    for(int i = 1; i <= n - 1; i++){
        cin >> a[i];
    }
    Mex mex(n);
    cout << mex.MEX() << '\n';
    return 0;
}
