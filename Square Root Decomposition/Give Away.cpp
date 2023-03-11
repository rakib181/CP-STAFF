#include<bits/stdc++.h>
using namespace std;
#define int long long int

const int inf = INT_MAX;

struct Square_Root_Decomposition{
    int n{}, d{}, b{};
    vector<int> a; vector<vector<int>> block;
    void init(vector<int> &v){
        this -> n = (int) v.size();
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
                if(a[i] > v) ans += 1;
            }
            return ans;
        }
        for(int i = l; i < (lb + 1) * d; i++){
            if(a[i] >= v) ans += 1;
        }
        for(int i = rb * d; i <= r; i++){
            if(a[i] >= v) ans += 1;
        }
        for(int i = lb + 1; i < rb; i++){
            ans += block[i].end() - lower_bound(block[i].begin(), block[i].end(), v);
        }
        return ans;
    }
}sq;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cin >> m;
    sq.init(a);
    while (m--){
        int type;
        cin >> type;
        if(!type){
            int l, r, v;
            cin >> l >> r >> v;
            l -= 1, r -= 1;
            cout << sq.query(l, r, v) << '\n';
        }else{
            int i, v;
            cin >> i >> v;
            i -= 1;
            sq.update(i, v);
        }
    }
    return 0;
}
