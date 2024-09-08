#include<bits/stdc++.h>
using namespace std;

#define long long long

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
    int mex(){
        return *missing_number.begin();
    }
};


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Mex mex(n + 5);
        vector<int> cnt(n + 1, 0);
        multiset<int> ms;
        for(int i = 1; i <= n; i++){
            int x;
            cin >> x;
            if(!cnt[x]){
                mex.add(x);
            }else{
                ms.insert(x);
            }
            cnt[x]++;
        }
        vector<long> ans(n + 1, -1); long add = 0;
        for(int cur_mex = 0; cur_mex <= n; cur_mex++){
            if(mex.mex() > cur_mex){
                ans[cur_mex] = cnt[cur_mex] + add;
            }else{
                if(mex.mex() == cur_mex){
                    ans[cur_mex] = add;
                }else{
                    auto it = ms.upper_bound(cur_mex - 1);
                    if(it == ms.begin())break;
                    it--;
                    ans[cur_mex] = cnt[cur_mex] + (cur_mex - *it - 1) + add;
                    add += (cur_mex - *it - 1);
                    cnt[*it]--;
                    ms.erase(ms.find(*it));
                    mex.add(cur_mex - 1);
                }
            }
        }
        for(int i = 0; i <= n; i++){
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
