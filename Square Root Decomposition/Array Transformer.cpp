#include<bits/stdc++.h>
using namespace std;
#define int long long int

const int inf = INT_MAX;

struct Square_Root_Decomposition{
    int n{}, d{}, u{}, b{};
    vector<int> a; vector<vector<int>> block;
    void init(vector<int> &v, int _u){
        this -> n = (int) v.size();
        this -> u = _u;
        this -> d = (int) sqrt(n) + 1;
        this -> a = v;
        this -> block.resize(n / d + 1);
        this -> b = 0;
        for(int i = 0; i < n; i++){
            block[b].push_back(a[i]);
            if((int) block[b].size() == d){
                b += 1;
            }
        }
        for(int i = 0; i < b; i++){
            sort(block[i].begin(), block[i].end());
        }
        if((int) block[b].size()) sort(block[b].begin(), block[b].end());
    }
    void update(int idx, int val){
         if(a[idx] == val)return;
         int old = a[idx], pos = 0; vector<int>& B = block[idx / d];
         int sz = (int) B.size();
         a[idx] = val;
        while (B[pos] < old) pos += 1;
        B[pos] = val;
        while (pos + 1 < sz and B[pos] > B[pos + 1]) swap(B[pos], B[pos + 1]), pos += 1;
        while (pos - 1 >= 0 and B[pos] < B[pos - 1]) swap(B[pos], B[pos - 1]), pos -= 1;
    }
    int query(int l, int r, int v){
        int lb = l / d, rb = r / d, ans = 0;
        if(lb == rb){
            for(int i = l; i <= r; i++){
                if(a[i] < v) ans += 1;
            }
            return ans;
        }
        for(int i = l; i < (lb + 1) * d; i++){
            if(a[i] < v) ans += 1;
        }
        for(int i = rb * d; i <= r; i++){
            if(a[i] < v) ans += 1;
        }
        for(int i = lb + 1; i < rb; i++){
            ans += lower_bound(block[i].begin(), block[i].end(), v) - block[i].begin();
        }
        return (ans * u) / (r - l + 1);
    }
}sq;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, u;
    cin >> n >> m >> u;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sq.init(a, u);
    while (m--){
        int l, r, v, p;
        cin >> l >> r >> v >> p;
        l -= 1, r -= 1, p -= 1;
        int k = sq.query(l, r, v);
        sq.update(p, k);
    }
    for(int i = 0; i < n; i++){
        cout << sq.a[i] << '\n';
    }
    return 0;
}
