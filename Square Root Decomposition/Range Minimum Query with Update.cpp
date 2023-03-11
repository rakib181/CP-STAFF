#include<bits/stdc++.h>
using namespace std;
#define int long long int

const int inf = INT_MAX;

struct Square_Root_Decomposition{
    int n{}, d{};
    vector<int> a, f;
    void init(vector<int> &v){
        this -> n = (int) v.size();
        this -> d = (int) sqrt(n) + 1;
        this -> a = v;
        this -> f.assign(d, inf);
        for(int i = 0; i < n; i++){
            f[i / d] = min(f[i / d], a[i]);
        }
    }
    void update(int idx, int val){
        int b = idx / d;
        a[idx] = val;
        f[b] = inf;
        for(int i = 0; i < d and d * b + i < n; i++){
            f[b] = min(f[b], a[d * b + i]);
        }
    }
    int get_min(int l, int r){
        int lb = l / d, rb = r / d, ans = inf;
        if(lb == rb){
            for(int i = l; i <= r; i++){
                ans = min(ans, a[i]);
            }
            return ans;
        }
        for(int i = lb + 1; i / d == lb; i++){
            ans = min(ans, f[i]);
        }
        for(int i = rb * d; i <= r; i++){
            ans = min(ans, a[i]);
        }
        return ans;
    }
}sq;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sq.init(a);
    while (q--){
        int type;
        cin >> type;
        if(type){
            int l, r;
            cin >> l >> r;
            cout << sq.get_min(l, r) << '\n';
        }else{
            int i, v;
            cin >> i >> v;
            sq.update(i, v);
        }
    }
    return 0;
}
