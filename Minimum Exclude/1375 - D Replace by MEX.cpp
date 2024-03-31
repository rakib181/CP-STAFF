#include<bits/stdc++.h>
using namespace std;
using ll = long long;

class Mex{
private:
    map<int, int> frequency;
    set<int> missing_number;
public:
    explicit Mex(int n){
        for(int i = 0; i <= n; i++){
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
        Mex mex(n + 5);
        for(int i = 0; i < n; i++){
            mex.add(a[i]);
        }
        int lst = n;
        vector<int> op;
        for(int i = 1; i <= 2 * n and lst > 0; i++){
            int new_mex = mex.MEX();
              if(new_mex == lst){
                  mex.del(a[lst - 1]);
                  a[lst - 1] = new_mex;
                  lst -= 1;
                  mex.add(a[lst]);
                  op.emplace_back(lst);
              }else{
                  mex.del(a[new_mex]);
                  a[new_mex] = new_mex;
                  mex.add(a[new_mex]);
                  op.emplace_back(new_mex);
              }
        }
        cout << (int) op.size() << '\n';
        for(auto x : op){
            cout << x + 1 << ' ';
        }
        cout << '\n';
    }
    return 0;
}
