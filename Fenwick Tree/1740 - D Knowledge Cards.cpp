#include<bits/stdc++.h>
using namespace std;
struct fenwick
{
    vector<int> fn;
    int n;
    void init(int _n){
        this -> n = _n;
        fn.resize(this -> n,0);
    }
    void add(int x,int val){
        while(x < n){
            fn[x] += val;
            x += x & (-x);
        }
    }
    int sum(int x){
        int sum = 0;
        while(x){
            sum += fn[x];
            x -= x & (-x);
        }
        return sum;
    }
};
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--) {
        fenwick fw;
        int n, m, k;
        cin >> n >> m >> k;
        fw.init(k + 100);
        vector<int> ar(k);
        for (int i = 0; i < k; i++) {
            cin >> ar[i];
        }
        bool ok = true;
        for (int i = 0; i < k; i++) {
            int cur = fw.sum(ar[i]);
            if (cur > n * m - 4) {
                ok = false;
                break;
            }
            fw.add(ar[i], 1);
        }
        if (ok) cout << "YA" << '\n';
        else cout << "TIDAK" << '\n';
    }
    return 0;
}
