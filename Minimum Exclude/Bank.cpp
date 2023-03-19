#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 5e5 + 9;
class Mex{
private:
    map<int, int> frequency;
    set<int> missing_number;
    vector<int> a;
public:
    int n = 5e5 + 9;
    explicit Mex(vector<int> const &a) : a(a){
        for(int i = 1; i < n; i++){
            missing_number.insert(i);
        }
        for(auto x : a){
            ++frequency[x];
            missing_number.erase(x);
        }
    }
    void RMV(){
        if(!missing_number.empty()){
            missing_number.erase(missing_number.begin());
        }
    }
    int MEX(){
        return *missing_number.begin();
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> a(N);
    Mex mx(a);
    multiset<int> call;
    while (q--){
        int type;
        cin >> type;
        if(type == 1){
            call.insert(mx.MEX());
            mx.RMV();
        }else if(type == 2){
            int x;
            cin >> x;
            auto it = call.find(x);
            if(it != call.end()){
                call.erase(it);
            }
        }else{
            cout << *call.begin() << '\n';
        }
    }
    return 0;
}
