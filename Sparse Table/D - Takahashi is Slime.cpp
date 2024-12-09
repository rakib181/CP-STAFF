#include <bits/stdc++.h>
using namespace std;
#define long long long

const int inf = 1e9 + 7;

struct ST{
    vector<vector<int>> t;
    vector<int> a;
    int lg = 25;
    ST() = default;
    explicit ST(int n, vector<int> b){
        this -> t.assign(lg, vector<int> (n + 10, 0));
        this -> a.assign(n + 2, 0);
        for(int i = 1; i <= n; i++){
            this -> a[i] = b[i];
        }
    }
    void build(int n){
        for(int i = 1; i <= n; i++){
            t[1][i] = a[i];
        }
        for(int i = 1; i < lg; i++){
            for(int j = 1; j + (1 << (i - 1)) <= n; j++){
                t[i + 1][j] = max(t[i][j], t[i][j + (1 << (i - 1))]);
            }
        }
    }
    int query(int l, int r){
        if(l > r)return inf;
        int _lg = __lg(r - l + 1) + 1;
        return max(t[_lg][l], t[_lg][r - (1 << (_lg - 1)) + 1]);
    }
};


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<long> p(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        p[i] = p[i - 1] + a[i];
    }
    ST sp(n, a);
    sp.build(n);
    auto get = [&](int l, int r) -> long{
        if(l > r)return 0;
        return p[r] - p[l - 1];
    };
    vector<long> ans(n + 1, 0);
    for(int i = 1; i <= n; i++){
        long s = a[i];
        int L = i, R = i;
        while (true){
            bool in = false;
            {
                int l = 1, r = L - 1, id = -1;
                while (l <= r){
                    int m = (l + r) >> 1;
                    if(sp.query(m, i - 1) < s){
                        id = m;
                        r = m - 1;
                    }else{
                        l = m + 1;
                    }
                }
                if(id != -1){
                    in = true;
                    s += get(id, L - 1);
                    L = id;
                }
            }
            {
                int l = R + 1, r = n, id = -1;
                while (l <= r){
                    int m = (l + r) >> 1;
                    if(sp.query(R + 1, m) < s){
                        id = m;
                        l = m + 1;
                    }else{
                        r = m - 1;
                    }
                }
                if(id != -1){
                    in = true;
                    s += get(R + 1, id);
                    R = id;
                }
            }
            if(!in)break;
        }
        ans[i] = s;
    }
    for(int i = 1; i <= n; i++){
        cout << ans[i] << " \n"[i == n];
    }
    return 0;
}
