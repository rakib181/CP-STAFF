#include<bits/stdc++.h>
using namespace std;

#define int long long int

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
        int n;
        cin >> n;
        vector<int> ar(n);
        for(int i = 0; i < n; i++){
            cin >> ar[i];
        }
        auto possible = [&](int k){
            multiset<int> st;
            for(int i = 0; i < n; i++)st.insert(ar[i]);
            for(int i = 1; i <= k; i++){
                if(st.empty())return false;
                int seek = k - i + 1;
                auto it = st.upper_bound(seek);
                if(it == st.begin())return false;
                it--;
                st.erase(it);
                if(!st.empty()) {
                    auto iter = st.begin();
                    int new_val = *iter;
                    new_val += seek;
                    st.erase(iter);
                    st.insert(new_val);
                }
            }
            return true;
        };
        int l = 0, r = n, ans = 0;
        while (l <= r){
            int mid = (l + r) >> 1;
            if(possible(mid)){
                ans = mid;
                l = mid + 1;
            }else r = mid - 1;
        }
        cout << ans << '\n';
    }
    return 0;
}
