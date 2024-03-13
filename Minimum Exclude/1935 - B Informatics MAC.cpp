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
    }

    void add(int x){
        frequency[x] += 1;
        missing_number.erase(x);
    }
    void del(int x){
        if(--frequency[x] == 0){
            missing_number.insert(x);
        }
    }
    int MEX(){
        return *missing_number.begin();
    }
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
       int n;
       cin >> n;
       vector<int> a(n);
       for(int i = 0; i < n; i++){
           cin >> a[i];
       }
       Mex lft(a);
       Mex rgt(a);
       for(int i = 0; i < n; i++){
           rgt.add(a[i]);
       }
       bool possible = false;
       for(int i = 0; i < n; i++){
            lft.add(a[i]);
            rgt.del(a[i]);
            if(lft.MEX() == rgt.MEX()){
                possible = true;
                cout << 2 << '\n';
                cout << 1 << ' ' << i + 1 << '\n';
                cout << i + 2 << ' ' << n << '\n';
                break;
            }
       }
       if(!possible)cout << "-1\n";
    }
    return 0;
}
