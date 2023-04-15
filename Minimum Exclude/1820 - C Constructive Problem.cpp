#include <bits/stdc++.h>
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
    int tt;
    cin >> tt;
    while(tt--){
       int n;
       cin >> n;
       vector<int> a(n);
       for(int i = 0; i < n; i++){
           cin >> a[i];
       }
       Mex mex(a);
       int mx = mex.MEX();
       int f = -1, l = -1;
       for(int i = 0; i < n; i++){
           if(a[i] == mx + 1){
               f = i;
               break;
           }
       }
       for(int i = n - 1; i >= 0; i--){
           if(a[i] == mx + 1){
               l = i;
               break;
           }
       }
       if(l == -1 and f == -1){
           if(mx + 1 <= n)cout << "YES\n";
           else cout << "NO\n";
           continue;
       }
       for(int i = f; i <= l; i++){
           mex.UPDATE(i, mx);
       }
       if(mex.MEX() == mx + 1)cout << "YES\n";
       else cout << "NO\n";
    }
    return 0;
}
