#include<bits/stdc++.h>
using namespace std;
using ll = long long;

class Mex{
private:
    vector<int> frequency;
    set<int> missing_number;
public:
    explicit Mex(int n){
        frequency.assign(n + 1, 0);
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
    int mex(){
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
        vector<int> a(n + 1);
        Mex mex(n); set<int> se{0};
        for(int i = 1; i <= n; i++){
            cin >> a[i]; se.insert(i);
            mex.add(a[i]);
        }
        vector<int> ans;
        int idx = 1;
        while(idx <= n){
            ans.emplace_back(mex.mex());
            vector<int> del;
            int id = idx;
            while(id <= n){
                del.emplace_back(a[id]);
                se.erase(a[id++]);
                if(*se.begin() == mex.mex()){
                    break;
                }
            }
            for(auto x : del){
                mex.del(x);
                se.insert(x);
            }
            idx = id;
        }
        cout << (int) ans.size() << '\n';
        for(int i = 0; i < (int) ans.size(); i++){
            cout << ans[i] << " \n"[i == (int) ans.size() - 1];
        }
    }
    return 0;
}
