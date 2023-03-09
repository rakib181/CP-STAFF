#include<bits/stdc++.h>
using namespace std;
#define int long long int

struct fenwick{
    int n{};
    vector<int> fn;
    void init(int _n){
        this -> n = _n;
        fn.assign(n + 1, 0);
    }

    void add(int idx, int val){
        idx += 1;
        while (idx < n){
            fn[idx] += val;
            idx += idx & (-idx);
        }
    }
    int sum(int idx){
        idx += 1; int tot = 0;
        while (idx){
          tot += fn[idx];
          idx -= idx & (-idx);
        }
        return tot;
    }
}fn;

vector<int> countSmaller(vector<int> nums) {
    int n = (int) nums.size();
    fn.init(2e5);
    vector<int> a(n),t(n);
    t = nums;
    sort(t.begin(), t.end());
    for(int i = 0; i < n; i++){
        int val = lower_bound(t.begin(), t.end(), nums[i]) - t.begin();
        nums[i] = val + 1;
    }
    for(int i = 0; i < n; i++){
        cout << nums[i] << ' ';
    }
    cout << '\n';
    for(int i = n - 1; i >= 0; i--){
        a[i] = fn.sum(nums[i] - 1);
        fn.add(nums[i] - 1, 1);
    }
    return a;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> nums = {5, 2, 6, 1};
    vector<int> ans = countSmaller(nums);
    for(auto x : ans){
        cout << x << ' ';
    }
    return 0;
}
